#include "io.h"
// Инициализация файлового потока
static stream_t stream_init(void)
{
    stream_t stream;
    stream.file = NULL;
    return stream;
}
// Функция обертка для файла
static FILE* get_file_from_stream_t(stream_t &stream)
{
    return stream.file;
}
// Обертка для fscanf
static int read_counts(FILE *file, int &n, int &m)
{
    if (fscanf(file, "%d %d", &n, &m) != 2)
    {
        return ERR_READ;
    }
    return OK;
}
// Обертка для fscanf
static int read_points(points_t *points, FILE *file, int i)
{
    if (fscanf(file, "%lf %lf %lf", &points[i].x, &points[i].y, &points[i].z) != 3)
    {
        return ERR_READ;
    }
    return OK;
}
// Обертка для fscanf
static int read_edges(edges_t *edges, FILE *file, int i)
{
    if (fscanf(file, "%d->%d", &edges[i].first, &edges[i].second) != 2)
    {
        return ERR_READ;
    }
    return OK;
}
// Функция чтения количеств из файла
static int read_counts_from_file(int *n, int *m, stream_t &stream)
{
    if (get_file_from_stream_t(stream))
    {
        if (read_counts(get_file_from_stream_t(stream), *n, *m) != OK) return ERR_READ;
    }
    else
        return ERR_READ;
    return OK;
}


// Функция чтения точек из файла
static int read_points_from_file(points_t *points, int n, stream_t &stream)
{
    int code_error = OK;
    if (get_file_from_stream_t(stream))
    {
        for (int i = 0; i < n && code_error == OK; i++)
            if (read_points(points, get_file_from_stream_t(stream), i) != OK) code_error = ERR_READ;
    }
    else
        code_error = ERR_READ;
    return code_error;
}
// Функция чтения ребер из файла
static int read_edges_from_file(edges_t *edges, int m, stream_t &stream)
{
    int code_error = OK;
    if (get_file_from_stream_t(stream))
    {
        for (int i = 0; i < m && code_error == OK; i++)
            if (read_edges(edges, get_file_from_stream_t(stream), i) != OK) code_error = ERR_READ;
    }
    else
        code_error = ERR_READ;
    return code_error;
}
// Функция обертка для открытия потока (чтение)
static int file_openning_read(stream_t &stream, char *filename)
{
    stream.file = fopen(filename, "r");
    if (stream.file)
    {
        return OK;
    }
    else
        return ERR_OPEN;
}
// Функция обертка для открытия потока (запись)
static int file_openning_save(stream_t &stream, char *filename)
{
    stream.file = fopen(filename, "w");
    if (stream.file)
        return OK;
    else
        return ERR_OPEN;
}

// Функция очистки модели
static void clear_model(model_t model)
{
    if (model.edges != NULL)
        free(model.edges);
    if (model.points != NULL)
        free(model.points);
}
// Функция копирования модели
static void copy_model(model_t &dist, model_t source)
{
    dist = source;
}

// Функция создания модели
static int create_model(model_t &model)
{
    model.points = (points_t*)malloc(model.count_of_points * sizeof(points_t));
    model.edges = (edges_t*)malloc(model.count_of_edges * sizeof(edges_t));

    if (model.points == NULL || model.edges == NULL) return ERR_MEMORY;

    return OK;
}
// Функция проверки на индексы, не больше ли они, чем кол-во точек в модели
static int check_input(model_t &model)
{
    for (int i = 0; i < model.count_of_edges; i++)
    {
        // if count of points is more than indexes
        if (model.count_of_points <= model.edges[i].first || model.count_of_points <= model.edges[i].second)
            return ERR_READ;
    }
    return OK;
}
// Функция чтения модели
static int read_model(model_t &model, stream_t &stream)
{
    int code_error = read_counts_from_file(&model.count_of_points, &model.count_of_edges, stream);

    if (code_error != OK) return code_error;

    code_error = create_model(model);

    if (code_error != OK) return code_error;

    code_error = read_points_from_file(model.points, model.count_of_points, stream);
    if (code_error == OK)
    {
        code_error = read_edges_from_file(model.edges, model.count_of_edges, stream);
    }
    if (code_error != OK)
    {
        clear_model(model);
        return code_error;
    }
    code_error = check_input(model);
    if (code_error != OK)
    {
        clear_model(model);
        return code_error;
    }

    return code_error;
}
// Функция закрытия потока
void close_stream(stream_t &stream)
{
    fclose(stream.file);
}
// Функция чтения модели
int read_model_from_file(model_t &model, parameters_t &parameters)
{
    stream_t stream = stream_init();
    int code_error = file_openning_read(stream, parameters.filename);

    if (code_error != OK) return code_error;

    model_t tmp = init();
    code_error = read_model(tmp, stream);
    close_stream(stream);
    if (code_error == OK)
    {
        clear_model(model);
        copy_model(model, tmp);
    }

    return code_error;
}

// Функция обертка для fscanf (запись)
static void print_counts(FILE *file, int n, int m)
{
    fprintf(file, "%d %d\n", n, m);
}
// Функция обертка для fscanf (запись)
static void print_points(model_t &model, FILE *file, int i)
{
    fprintf(file, "%lf %lf %lf\n", get_x_index_point(model, i), get_y_index_point(model, i), get_z_index_point(model, i));
}
// Функция обертка для fscanf (запись)
static void print_edges(model_t &model, FILE *file, int i)
{
    fprintf(file, "%d->%d\n", get_first_index_edge(model, i), get_second_index_edge(model, i));
}
// Функция сохранения модели в файл
int save_changes(model_t &model, parameters_t &parameters)
{
    int code_error = OK;
    if (!model.points || !model.edges)
    {
        code_error = ERR_SAVE;
        return code_error;
    }
    stream_t stream = stream_init();
    code_error = file_openning_save(stream, parameters.filename);
    if (code_error == OK)
    {
        int n = get_count_of_points(model);
        int m = get_count_of_edges(model);
        print_counts(get_file_from_stream_t(stream), n, m);
        for (int i = 0; i < n; i++)
        {
            print_points(model, get_file_from_stream_t(stream), i);
        }
        for (int i = 0; i < m; i++)
        {
            print_edges(model, get_file_from_stream_t(stream), i);
        }
        close_stream(stream);
    }
    else
    {
        code_error = ERR_SAVE;
        return code_error;
    }
    return code_error;
}
