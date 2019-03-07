# Нарисовать заштрихованную фигуру, затем ее переместитть, промасштабировать
# и повернуть. Кардиоида ( ее уравнение х = acost(1 + cost); y = asint(1 + cost)
# a > 0; t принадлежит от 0 до 2п включая границы
#
#todo Добавить нормальную штриховку, проверку ввода, если пустые поля или не действительные числа
#Информация добавить

import os
from tkinter import *
from tkinter import messagebox
from math import sqrt, acos, pi, cos, sin


global triangle_step
global x_y_step
global x_y_sh_step

def get_koef(xmax, xmin, ymax, ymin, curr_x, curr_y):
    KXmax = 1050
    KXmin = 70
    KYmax = 650
    KYmin = 70
 
    KX = (KXmax - KXmin) / (xmax -xmin)
    KY = (KYmax - KYmin) / (ymax - ymin)
    K =  min(KX, KY)
    XK = round(70 + (curr_x - xmin)*K)
    XY = round(20 + (ymax - curr_y)*K)
    print("param", XK, XY)
    return XK, XY

def is_float(num):
    try:
        val = float(num)
        # print("Float")
        return 1
    except:
        # print("No")
        return 0


def change_pos(triangle, x_y, x_y_sh):
    global triangle_step
    global x_y_step
    global x_y_sh_step
    print("triangle", triangle)
    #print("x_y:", x_y)

    dx = ent_transfer1.get()
    dy = ent_transfer2.get()
    #print("dx, dy", dx, dy)
    if (is_float(dx) and is_float(dy)):
        C.delete('all')
        lenght = len(x_y)
        j = 0
        while (j < lenght - 1):
            x_y[j] += float(dx)
            x_y[j + 1] += float(dy)
            #print(j, j + 1)
            j += 2

        triangle[0] += float(dx)
        triangle[1] += float(dy)
        triangle[2] += float(dx)
        triangle[3] += float(dy)
        triangle[4] += float(dx)
        triangle[5] += float(dy)
        
        C.create_line(triangle[0], triangle[1], triangle[2], triangle[3])
        C.create_line(triangle[0], triangle[1], triangle[4], triangle[5])
        C.create_line(triangle[4], triangle[5], triangle[2], triangle[3])

        lenght = len(x_y_sh)
        j = 0
        while (j < lenght - 1):
            x_y_sh[j] = x_y_sh[j] + float(dx)
            x_y_sh[j + 1] = x_y_sh[j + 1] + float(dy)
            j += 2
        i = 0
        while (i <= lenght - 3):
            C.create_line(x_y_sh[i], x_y_sh[i + 1], x_y_sh[i + 2], x_y_sh[i + 3])
            i += 4
        C.create_polygon(x_y, fill = "white", outline = "black")
        return triangle, x_y
    else:
        messagebox.showinfo("Внимание", "Проверьте правильность ввода!")

def scale_pos(triangle, x_y, x_y_sh):
    print("trinangle", triangle)
    
    global triangle_step
    global x_y_step
    global x_y_sh_step
    triangle_step = list(triangle)
    x_y_sh_step = list(x_y_sh)
    x_y_step = list(x_y)
    KX = ent_scaling_c1.get()
    KY = ent_scaling_c2.get()

    XC = ent_scaling_k1.get()
    YC = ent_scaling_k2.get()
    if ( is_float(KX) and is_float(KY) and is_float(XC) and is_float(YC)):
        C.delete('all')
        lenght = len(x_y)
        j = 0
        while (j < lenght - 1):
            x_y[j] = x_y[j] * float(KX) + (1 - float(KX)) * (float(XC) + 400)
            x_y[j + 1] = x_y[j + 1] * float(KY) + (1 - float(KY)) * (float(YC) + 400)
            #print(j, j + 1)
            j += 2

        triangle[0] = triangle[0] * float(KX) + (1 - float(KX)) * (float(XC) + 400)
        triangle[1] = triangle[1] * float(KY) + (1 - float(KY)) * (float(YC) + 400)
        triangle[2] = triangle[2] * float(KX) + (1 - float(KX)) * (float(XC) + 400)
        triangle[3] = triangle[3] * float(KY) + (1 - float(KY)) * (float(YC) + 400)
        triangle[4] = triangle[4] * float(KX) + (1 - float(KX)) * (float(XC) + 400)
        triangle[5] = triangle[5] * float(KY) + (1 - float(KY)) * (float(YC) + 400)
        
        C.create_line(triangle[0], triangle[1], triangle[2], triangle[3])
        C.create_line(triangle[0], triangle[1], triangle[4], triangle[5])
        C.create_line(triangle[4], triangle[5], triangle[2], triangle[3])

        lenght = len(x_y_sh)
        j = 0
        while (j < lenght - 1):
            x_y_sh[j] = x_y_sh[j] * float(KX) + (1 - float(KX)) * (float(XC) + 400)
            x_y_sh[j + 1] = x_y_sh[j + 1] * float(KY) + (1 - float(KY)) * (float(YC) + 400)
            j += 2
        i = 0
        while (i <= lenght - 4):
            C.create_line(x_y_sh[i], x_y_sh[i + 1], x_y_sh[i + 2], x_y_sh[i + 3])
            i += 4
        C.create_polygon(x_y, fill = "white", outline = "black")
        
        return triangle, x_y, x_y_sh
    else:
        messagebox.showinfo("Внимание", "Проверьте правильность ввода!")

def rotate_pos(triangle, x_y, x_y_sh):
    print("trinangle", triangle)
    global triangle_step
    global x_y_step
    global x_y_sh_step
    triangle_step = list(triangle)
    x_y_sh_step = list(x_y_sh)
    x_y_step = list(x_y)
    angle = ent_rotate_angle.get()
    xc1 = ent_rotate_c1.get()
    yc1 = ent_rotate_c2.get()
    if (is_float(angle) and is_float(xc1) and is_float(yc1)):
        C.delete('all')    
        xc = float(xc1) + 400
        yc = float(yc1) + 400
        lenght = len(x_y)
        j = 0
        while (j < lenght - 1):
            x1 = xc + (x_y[j] - xc) * cos(float(angle))\
                      + (x_y[j + 1] - yc) * sin(float(angle))
            y1 = yc + (x_y[j + 1] - yc) * cos(float(angle))\
                      - (x_y[j] - xc) * sin(float(angle))
            #print(j, j + 1)
            x_y[j] = x1
            x_y[j + 1] = y1
            j += 2
        x1 = xc + (triangle[0] - xc) * cos(float(angle))\
                      + (triangle[1] - yc) * sin(float(angle))
        y1 = yc + (triangle[1] - yc) * cos(float(angle))\
                      - (triangle[0] - xc) * sin(float(angle))
        triangle[0] = x1
        triangle[1] = y1

        x1 = xc + (triangle[2] - xc) * cos(float(angle))\
                      + (triangle[3] - yc) * sin(float(angle))
        y1 = yc + (triangle[3] - yc) * cos(float(angle))\
                      - (triangle[2] - xc) * sin(float(angle))
        
        triangle[2] = x1
        triangle[3] = y1

        x1 = xc + (triangle[4] - xc) * cos(float(angle))\
                      + (triangle[5] - yc) * sin(float(angle))
        y1 = yc + (triangle[5] - yc) * cos(float(angle))\
                      - (triangle[4] - xc) * sin(float(angle))

        triangle[4] = x1
        triangle[5] = y1
        
        C.create_line(triangle[0], triangle[1], triangle[2], triangle[3])
        C.create_line(triangle[0], triangle[1], triangle[4], triangle[5])
        C.create_line(triangle[4], triangle[5], triangle[2], triangle[3])

        lenght = len(x_y_sh)
        j = 0
        while (j < lenght - 1):
            x1 = xc + (x_y_sh[j] - xc) * cos(float(angle))\
                      + (x_y_sh[j + 1] - yc) * sin(float(angle))
            y1 = yc + (x_y_sh[j + 1] - yc) * cos(float(angle))\
                      - (x_y_sh[j] - xc) * sin(float(angle))
            #print(j, j + 1)
            x_y_sh[j] = x1
            x_y_sh[j + 1] = y1
            j += 2
        i = 0
        print(x_y_sh)
        while (i <= lenght - 4):
            C.create_line(x_y_sh[i], x_y_sh[i + 1], x_y_sh[i + 2], x_y_sh[i + 3])
            i += 4
        
        C.create_polygon(x_y, fill = "white", outline = "black")
        
        return triangle, x_y, x_y_sh, triangle_step, x_y_sh_step
    else:
        messagebox.showinfo("Внимание", "Проверьте правильность ввода!")
def info():
    messagebox.showinfo("Информация", "- Для поворота экрана заполните \
соответствующие поля и наэмите на кнопку\" Повернуть\"\n \n\
- Для масштабирования изображения введите коэффициенты масштабирования\
 и центр масштабирования и нажмите на соответствующую кнопку\n \n\
- Для поворота изображения введите центр поворота и угол в радианах!\n\
Координаты центра - центр полотна (0, 0)")

def get_back_by_step(triangle1, x_y1, x_y_sh1):
    C.delete('all')
    global triangle
    global x_y
    global x_y_sh
    C.create_line(triangle1[0],triangle1[1], triangle1[2], triangle1[3])
    C.create_line(triangle1[0],triangle1[1], triangle1[4], triangle1[5])
    C.create_line(triangle1[4],triangle1[5], triangle1[2], triangle1[3])
    lenght = len(x_y_sh1)
    i = 0
    print(x_y_sh1)
    while (i <= lenght - 4):
        C.create_line(x_y_sh1[i], x_y_sh1[i + 1], x_y_sh1[i + 2], x_y_sh1[i + 3])
        i += 4
    triangle = list(triangle1)
    x_y =list(x_y1)
    x_y_sh = list(x_y_sh1)
    C.create_polygon(x_y, fill = "white", outline = "black")

def get_back(triangle1, x_y1, x_y_sh1):
    C.delete('all')
    global triangle
    global x_y
    global x_y_sh
    C.create_line(triangle1[0],triangle1[1], triangle1[2], triangle1[3])
    C.create_line(triangle1[0],triangle1[1], triangle1[4], triangle1[5])
    C.create_line(triangle1[4],triangle1[5], triangle1[2], triangle1[3])
    lenght = len(x_y_sh1)
    i = 0
    print(x_y_sh1)
    while (i <= lenght - 4):
        C.create_line(x_y_sh1[i], x_y_sh1[i + 1], x_y_sh1[i + 2], x_y_sh1[i + 3])
        i += 4
    triangle = list(triangle1)
    x_y =list(x_y1)
    x_y_sh = list(x_y_sh1)
    C.create_polygon(x_y1, fill = "white", outline = "black")
    return triangle1, x_y1, x_y_sh1

root = Tk()
root.title('Игра в имитацию')
root.geometry('1610x900')
root.resizable(width=False, height=False)
menu=Menu(root)
menu.add_command(label='Информация', command = info)
root.config(menu=menu)
WORK_PATH=os.path.abspath(os.getcwd())
bg_image=PhotoImage(file=os.path.join(WORK_PATH,'фон4.PNG'))
bg=Label(root,image=bg_image)

C = Canvas(root,width=1050,height=650,bg='white')
C.place(x=10,y=10)


# Построение кардиоиды

a = 70
t = 0

x_y = []
y = []

eps = 0.05

max_x = 0
max_y = 0
min_x = 1600
min_y = 800
triangle = []
flag = 0
while (t < 2 * pi):
    x1 = a * cos(t) * (1 + cos(t)) + 400
    y1 = a * sin(t) * (1 + cos(t)) + 400
    
    if y1 < min_y:
        min_y = y1
    if y1 > max_y:
        max_y = y1
    if x1 < min_x:
        min_x = x1
    if x1 > max_x:
        max_x = x1
    x_y.append(x1)
    x_y.append(y1)
    t += 0.1

print("max_x, max_y, min_x, min_y",max_x, max_y, min_x, min_y)

#верхняя точка
triangle.append(min_x + (max_x - min_x) / 2)
triangle.append((max_y - a * 5))
# Левая точка
triangle.append((min_x - a * 3))
triangle.append((max_y + a ))
# Правая точка
triangle.append((max_x + a * 3))
triangle.append((max_y + a ))

C.create_line(triangle[0],triangle[1], triangle[2], triangle[3])
C.create_line(triangle[0],triangle[1], triangle[4], triangle[5])
C.create_line(triangle[4],triangle[5], triangle[2], triangle[3])

i = triangle[1]
x_i = 0

razn = (triangle[4] - triangle[0]) / (triangle[5] - triangle[1])
x_y_sh = []
print(i)
print(triangle[5])
while (i < triangle[5]):
    x_y_sh.append(triangle[0] - x_i)
    x_y_sh.append(i)
    x_y_sh.append(triangle[0] + x_i)
    x_y_sh.append(i)
    C.create_line((triangle[0] - x_i), i, triangle[0] + x_i, i)
    i += a / 2
    x_i += a * razn / 2

triangle_base = list(triangle)
x_y_sh_base = list(x_y_sh)
x_y_base = list(x_y)

triangle_step = list(triangle)
x_y_sh_step = list(x_y_sh)
x_y_step = list(x_y)

print(triangle)
C.create_polygon(x_y, fill = "white", outline = "black")

#C.create_oval(triangle[0], triangle[1], triangle[0] + 3, triangle[1] + 3)

# Перенос
ent_transfer1 = Entry(width=20)
ent_transfer1.place(x=1200,y=150)

ent_transfer2 = Entry(width=20)
ent_transfer2.place(x=1400,y=150)

l = Label(root,text='Перенос изображения\n Введите коэффициенты переноса: ',bg = "#426084",\
          fg = "white", font=("Helvetica", 16)).place(x=1200,y = 90)

but_transfer = Button(root,text='Переместить',command = lambda: change_pos(triangle, x_y, x_y_sh), width=10,height=1,bg='white',fg='black')
but_transfer.place(x=1325,y=190)

# Масштабирование
ent_scaling_c1 = Entry(width=20)
ent_scaling_c1.place(x=1200,y=310)

ent_scaling_c2 = Entry(width=20)
ent_scaling_c2.place(x=1400,y=310)

ent_scaling_k1 = Entry(width=20)
ent_scaling_k1.place(x=1200,y=340)

ent_scaling_k2 = Entry(width=20)
ent_scaling_k2.place(x=1400,y=340)

l = Label(root,text='Масштабирование изображения\n Введите коэффициенты центра и масштаб.: ',bg = "#426084",\
          fg = "white", font=("Helvetica", 16)).place(x=1100,y = 250)
but_scaling = Button(root,text='Масштабировать', command = lambda: scale_pos(triangle, x_y, x_y_sh), width=15,height=1,bg='white',fg='black')
but_scaling.place(x=1310,y=380)

# Rotate
ent_rotate_c1 = Entry(width=20)
ent_rotate_c1.place(x=1200,y=540)

ent_rotate_c2 = Entry(width=20)
ent_rotate_c2.place(x=1400,y=540)

ent_rotate_angle = Entry(width=20)
ent_rotate_angle.place(x=1300,y=580)

l = Label(root,text='Поворот изображения\n Введите коэффициенты центра и\n угол для поворота: ',bg = "#426084",\
          fg = "white", font=("Helvetica", 16)).place(x=1200,y = 450)


but_rotate = Button(root,text='Повернуть', command = lambda: rotate_pos(triangle, x_y, x_y_sh), width=15,height=1,bg='white',fg='black')
but_rotate.place(x=1305,y=620)


but_return_step = Button(root,text='Вернуться на шаг назад', command = lambda: \
                         get_back_by_step(triangle_step, x_y_step, x_y_sh_step), width=25,height=1,bg='white',fg='black')
but_return_step.place(x=1270,y=670)

but_return = Button(root,text='Вернуться к исходному изображению', command = lambda: get_back(triangle_base, x_y_base, x_y_sh_base),width=30,height=1,bg='white',fg='black')
but_return.place(x=1250,y=700)

l = Label(root,text='Исходное уравнение: \n х = a * cos(t) * (1 + cos(t));\n y = a * sin(t) * (1 + cos(t))',bg = "#7eb93b",\
          fg = "white", font=("Helvetica", 16)).place(x=170,y = 700)
l = Label(root,text='Отсчет начинается с середины полотна для рисования',bg = "#7eb93b",\
          fg = "white", font=("Helvetica", 16)).place(x=170,y = 780)
l = Label(root,text='dx',bg = "#426084",\
          fg = "white", font=("Helvetica", 16)).place(x=1170,y = 145)
l = Label(root,text='dy',bg = "#426084",\
          fg = "white", font=("Helvetica", 16)).place(x=1370,y = 145)
l = Label(root,text='kx',bg = "#426084",\
          fg = "white", font=("Helvetica", 16)).place(x=1170,y = 300)
l = Label(root,text='ky',bg = "#426084",\
          fg = "white", font=("Helvetica", 16)).place(x=1370,y = 300)

l = Label(root,text='xc',bg = "#426084",\
          fg = "white", font=("Helvetica", 16)).place(x=1170,y = 330)
l = Label(root,text='yc',bg = "#426084",\
          fg = "white", font=("Helvetica", 16)).place(x=1370,y = 330)

l = Label(root,text='xc',bg = "#426084",\
          fg = "white", font=("Helvetica", 16)).place(x=1170,y = 535)
l = Label(root,text='yc',bg = "#426084",\
          fg = "white", font=("Helvetica", 16)).place(x=1370,y = 535)

l = Label(root,text='angle',bg = "#426084",\
          fg = "white", font=("Helvetica", 16)).place(x=1240,y = 575)

#ent3 = Entry(width=20)
#ent3.place(x=1100,y=610)


##C.create_line(30, 630, 150, 630)
##C.create_line(30, 630, 30, 530)
##C.create_line(30, 530, 20, 550)
##C.create_line(30, 530, 40, 550)
##C.create_line(150, 630, 130, 620)
##C.create_line(150, 630, 130, 640)

#messagebox.showinfo('Информация','Внимательно прочитайте условия ввода. Введите координаты, а затем нажмите на кнопку "записать!"\
#Для построения треугольника нужно минимум 3 точки!')

bg.pack()
root.mainloop()
