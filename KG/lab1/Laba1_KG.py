# На плоскости дано множество точек. Найти такой треугольник, у которого угол между медианой и биссектрисой, выходящей из одной из вершины, максимален.
# ( для каждого треугольника рассматривать все три вершины и выбирать максимальное значение угла и номер вершины для ввода в гр. режиме)
# Сделать вывод изображения в гр.режиме
#
#
#
#
#
#
#
#

import os
from tkinter import *
from tkinter import messagebox
from math import sqrt, acos, pi

# удаление выделенного элемента
def delete():
    selection = lstbox.curselection()
    lstbox.delete(selection[0])

def add_in(line):
    selection = lstbox.curselection()
    lstbox.insert(selection[0])
    lstbox.delete(selection[0] + 1)
    
class EditWindow:  # Класс окна редактирования
    def __init__(self):
        self.top = Toplevel()
        self.top.title("Редактирование")
        self.top.geometry('300x150')
        self.top.configure(bg='lightblue')
        lab1_top = Label(self.top,
                         text='Введите новые координаты точки (X Y): ',
                         font='Arial 16', bg='lightblue')
        self.lab2_top = Label(self.top, text='', font='Arial 12',
                              bg='lightblue', fg='#B22222')
        self.ent_top = Entry(self.top, width=12, bg='white', font='Arial 12',
                             bd=2)
        but_top = Button(self.top, text='Редактировать', width=15, height=1)
        self.el = lstbox.curselection()

        but_top['command'] = self.edit

        lab1_top.place(x=10, y=30)
        self.lab2_top.place(x=80, y=55)
        self.ent_top.place(x=20, y=80)
        but_top.place(x=150, y=83)

    def edit(self):  # Функция редактирования точки
        s = StringVar()
        s = self.ent_top.get()
        s = s.strip()
        if s.find(' ') != -1 and s.count(' ') == 1:
            x, y = s.split()
            if x.isdigit() and y.isdigit():
                lstbox.delete(self.el[0])
                lstbox.insert(self.el[0], str(s))
                self.top.destroy()
            else:
                self.lab2_top.configure(text='Некорректное значение')
        else:
            self.lab2_top.configure(text='Некорректное значение')

 

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
    
def vision():
    C.delete('all')
    c = lstbox.get(0)
    C.create_line(30, 630, 150, 630)
    C.create_line(30, 630, 30, 530)
    C.create_line(30, 530, 20, 550)
    C.create_line(30, 530, 40, 550)
    C.create_line(150, 630, 130, 620)
    C.create_line(150, 630, 130, 640)
    if len(c) == 0:
        messagebox.showwarning('Ошибка!',' Лист пуст или введены отрицательные координаты')
    else:
        xm=[]
        ym=[]
        size = lstbox.get(0,END)
        #n = size.split(' ')
        for i in size:
            xy = i.split(' ')
            x = xy[0]
            y = xy[1]
            #print('иксы', x)
            #print('игрики', y)
            xm.append(float(x))
            ym.append(float(y))
        #print("len(xm)", len(xm))
        #print("xm is ", xm)
        Xmax = max(xm)
        Xmin = min(xm)
        Ymax = max(ym)
        Ymin = min(ym)
        #print("Xmax Xmin", Xmax, Xmin)
        
        
        #print("max min", KXmax, KXmin)
        if ((len(xm)) < 3):
            messagebox.showinfo('Ошибка!',' Введено менее 3-х точек!')
        else:
            maximum = 0
            print(len(size))
            for i in range(len(size) - 2):
                for j in range(i + 1, len(size) - 1):
                    for k in range(j + 1, len(size)):
                        
                        a= abs(float(xm[j])-float(xm[i]))
                        b= abs(float(xm[k])-float(xm[i]))
                        c= abs(float(xm[k])-float(xm[j]))
                        d= abs(float(ym[j])-float(ym[i]))
                        f= abs(float(ym[k])-float(ym[i]))    
                        g= abs(float(ym[k])-float(ym[j]))                 
       
                        A1 = sqrt(b**2+f**2)     
                        B1 = sqrt(a**2+d**2)      
                        C1 = sqrt(g**2+c**2)
                        print("A1 B1 C1", A1, B1, C1)
                        
                        cosalpha = (B1 * B1 + C1 * C1 - A1 * A1) / (2 * B1 * C1) 
                        cosbeta = (A1 * A1 + C1 * C1 - B1 * B1) / (2 * A1 * C1)
                        cosgamma = (B1 * B1 + A1 * A1 - C1 * C1) / (2 * B1 * A1)
                        print("cosa, cosb, cosg", cosalpha, cosbeta, cosgamma)
##                        if (cosalpha > 1):
##                            cosalpha = 1
##                        if (cosalpha < 1):
##                            cosalpha = -1
##                        if (cosbeta > 1):
##                            cosbeta = 1
##                        if (cosbeta < 1):
##                            cosbeta = -1    
##                        if (cosgamma > 1):
##                            cosgamma = 1
##                        if (cosgamma < 1):
##                            cosgamma = -1
                        alpha = acos(round(cosalpha, 6)) * 180 / pi
                        beta = acos(round(cosbeta, 6)) * 180 / pi
                        gamma = acos(round(cosgamma, 6)) * 180 / pi

                        mediana1 = sqrt(2 * pow(C1,2) + 2 * pow(B1, 2) - pow(A1, 2))/2
                        mediana2 = sqrt(2 * pow(A1,2) + 2 * pow(B1, 2) - pow(C1, 2))/2
                        mediana3 = sqrt(2 * pow(C1,2) + 2 * pow(A1, 2) - pow(B1, 2))/2
                        print("mediana1 <C1B1 ",mediana1)
                        print("mediana2 <A1B1",mediana2)
                        print("mediana3 <C1A1",mediana3)

                        a_2 = A1 / 2
                        b_2 = B1 / 2
                        c_2 = C1 / 2
                        print(a_2)
                        
                        alpha1 = acos(round(((pow(C1, 2) + pow(mediana1, 2) - pow(a_2, 2)) / (2 * mediana1 * C1)), 6)) * 180 / pi
                        beta1 = acos(round((pow(mediana3, 2) + pow(A1, 2) - pow(b_2, 2)) / (2 * mediana3 * A1), 6)) * 180 / pi
                        gamma1 = acos(round((pow(mediana2, 2) + pow(A1, 2) - pow(c_2, 2)) / (2 * mediana2 * A1), 6))* 180 / pi

                        print("alpha1, beta1, gamma1", alpha1, beta1, gamma1)

                        raznica1 = abs((alpha / 2) - alpha1) 
                        raznica2 = abs((beta / 2) - beta1)
                        raznica3 = abs((gamma / 2) - gamma1)
                        
                        #razn_a = abs((gamma - beta) / 2)
                        #razn_b = abs((alpha - gamma) / 2)
                        #razn_g = abs((alpha - beta) / 2)
                        raznica = max (raznica1, raznica2, raznica3)
                        print("razn", raznica)
                        
                        if raznica >= maximum:
                            if ( alpha != 0 and beta != 0 and gamma != 0): 
                                maximum = raznica
                                massive1 = []
                                massive2 = []
                                massive3 = []
                                massive1.append(xm[j])
                                massive1.append(ym[j])
                                massive2.append(xm[k])
                                massive2.append(ym[k])
                                massive3.append(xm[i])
                                massive3.append(ym[i])
            if (maximum != 0):
                    
                print(massive1,massive2,massive3)
                    
                x2,y2 = get_koef(int(Xmax), int(Xmin), int(Ymax), int(Ymin), int(massive1[0]), int(massive1[1]))
                x3,y3 = get_koef(int(Xmax), int(Xmin), int(Ymax), int(Ymin), int(massive2[0]), int(massive2[1]))
                x4,y4 = get_koef(int(Xmax), int(Xmin), int(Ymax), int(Ymin), int(massive3[0]), int(massive3[1]))

                #if ((x4 - x2) / (x3 - x2) != (y4 - y2) / (y3 - y2)):
                        
                C.create_oval(x2,y2,x2 + 3,y2 + 3, width=1, fill='blue')
                C.create_oval(x3,y3,x3 + 3,y3 + 3, width=1, fill='blue')
                C.create_oval(x4,y4,x4 + 3,y4 + 3, width=1, fill='blue')
                    
                C.create_text(x2 - 10,y2 - 10,text = '(' + str(massive1[0]) + ',' + str(massive1[1]) + ')')
                C.create_text(x3 - 10,y3 - 10,text = '(' + str(massive2[0]) + ',' + str(massive2[1]) + ')')
                C.create_text(x4 - 10,y4 - 10,text = '(' + str(massive3[0]) + ',' + str(massive3[1]) + ')')
                    
                C.create_line(x2,y2,x3,y3,width=1,fill='blue')
                C.create_line(x2,y2,x4,y4,width=1,fill='blue')
                C.create_line(x3,y3,x4,y4,width=1,fill='blue')
                C.create_text(100, 30, text = "Макс. угол:" + str(maximum))
                    #else:
                       # messagebox.showwarning('Внимание!',' Треугольник - вырожденный')
            else:
                    messagebox.showwarning('Внимание!',' Треугольник - вырожденный') 
    


    

def is_presented(line):
    print("=====")
    size = lstbox.get(0,END)
    c = lstbox.get(0)
    if (c == 0):
        return 0
    for i in size:
        #print("line", line)
        #print("i", i)
        if line == i:
            return 1
    return 0
    
        
def change(*args):
    selection = lstbox.curselection()
    print("selevtion", selection)
    if len(selection) == 0:
        messagebox.showwarning('Внимание!',' Не выбран элемент!')
    else:  
        line = ent.get()
        print("line is ", line)
        m = line.split(' ')
        if len(m) == 2:
            
            if m[0][0]=='-':
                l=m[0][1:]
            else:
                l=m[0][0]
            if m[1][0]=='-':
                l1=m[1][1:]
            else:
                l1=m[1][0]
            if l1.isdigit() and l.isdigit():
                int1 = is_presented(line)
                print("int1", int1)
                if (is_presented(line) == 0):
                    lstbox.insert(selection, line)
                    ent.delete(selection,END)
                else:
                    ent.delete(0,END)
                    messagebox.showwarning('Error','Такая точка уже присутствует')
                    
            else:
                messagebox.showwarning('Error','вы явно ввели не координаты')
                ent.delete(0,END)
                print('error')
        else:
            messagebox.showwarning('Error','Введите координаты точки, на которую хортите заменить!')
            ent.delete(0,END)
            print('error')
        
def add(*args):
    line = ent.get()
    print("line is ", line)
    m = line.split(' ')
    if len(m) == 2:
        
        if m[0][0]=='-':
            l=m[0][1:]
        else:
            l=m[0][0]
        if m[1][0]=='-':
            l1=m[1][1:]
        else:
            l1=m[1][0]
        if l1.isdigit() and l.isdigit():
            if (is_presented(line) == 0):
                lstbox.insert(0, line)
                ent.delete(0,END)
            else:
                ent.delete(0,END)
                messagebox.showwarning('Error','Такая точка уже присутствует')
                
        else:
            messagebox.showwarning('Error','вы явно ввели не координаты')
            ent.delete(0,END)
            print('error')
    else:
        messagebox.showwarning('Error','Проверьте правильность ввода!')
        ent.delete(0,END)
        print('error')
    
    
# Очистка всего Listbox'a
def delete():
    lstbox.delete(0,END)

def edit_top(event):  # Функция вызова окна редактирования точки
    el = lstbox.curselection()
    if len(el) > 0:
        top = EditWindow()

# Удаление выбранноо элемента
def delete1():
    selection = lstbox.curselection()
    if len(selection) == 0:
        print('Error')
        messagebox.showwarning('Ошибка!',' Не выбран элемент!')
    else:
        lstbox.delete(selection[0])

# Очистка канваса
def clear():
    C.delete('all')


root = Tk()
root.title('Построение треугольника с максимальным углом между высотой и биссектрисой')
root.geometry('1610x900')
WORK_PATH=os.path.abspath(os.getcwd())
bg_image=PhotoImage(file=os.path.join(WORK_PATH,'фон1.PNG'))
bg=Label(root,image=bg_image)
scrollbar = Scrollbar(root)
scrollbar.pack(side=RIGHT,fill=Y)

l = Label(root,text='введите координаты: ',bg = "white",\
          fg = "black").place(x=1100,y=80)
l = Label(root,text='формат ввода:\n Координаты точки \nчерез пробел (x, y)',bg = "white",\
          fg = "black").place(x=1105,y=20)


l = Label(root,text='1) Введите координаты точек\n(Минимум 3) треугольника\n через пробел в поле ввода\n\
 слева и нажмите на "Записать" \nзатем нажмите на кнопку \n\"отобразить\"',bg = "white",\
          fg = "black", font=("Helvetica", 16)).place(x=1270,y=50)

l = Label(root,text='2) Для изменения значения \nточек выберите значение \n в поле и \n нажмите на \nкнопку \"изменить\", \
далее \nвведите координаты и \nнажмите на кнопку \n\"Редактировать\"', bg = "white",\
          fg = "black", font=("Helvetica", 16)).place(x=1270,y=300)

#l = Label(root,text='введите координаты: ', font=("Helvetica", 16)).place(x=1100,y=600)
ent = Entry(width=20)
ent.place(x=1100,y=110)

but = Button(root,text='Записать!',command=add,width=20,height=1,bg='yellow',fg='black')
but.place(x=1090,y=150)

but1 = Button(root,text='Отобразить',command=vision,width=10,height=1,bg='yellow',fg='black')
but1.place(x=1125,y=650)

but2 = Button(root,text='Очистить список!',command=delete,width=20,height=1,bg='yellow',fg='black')
but2.place(x=1090,y=600)

but3 = Button(root,text='Удалить элемент',command=delete1,width=20,height=1,bg='yellow',fg='black')
but3.place(x=1090,y=560)

but4 = Button(root,text='Очистить поле ',command=clear,width=30,height=1,bg='yellow',fg='black')
but4.place(x=450,y=700)

but5 = Button(root,text='Изменить значение элемента',width=27,height=1,bg='yellow',fg='black')
but5.place(x=1070,y=520)
but5.bind('<Button-1>', edit_top)



root.bind('<Return>',add)

lstbox = Listbox(yscrollcommand=scrollbar.set,height=20)
lstbox.place(x=1100,y=190)
scrollbar.config(command=lstbox.yview)

C = Canvas(root,width=1050,height=650,bg='white')
C.place(x=10,y=10)

C.create_line(30, 630, 150, 630)
C.create_line(30, 630, 30, 530)
C.create_line(30, 530, 20, 550)
C.create_line(30, 530, 40, 550)
C.create_line(150, 630, 130, 620)
C.create_line(150, 630, 130, 640)

#messagebox.showinfo('Информация','Внимательно прочитайте условия ввода. Введите координаты, а затем нажмите на кнопку "записать!"\
#Для построения треугольника нужно минимум 3 точки!')

bg.pack()
root.mainloop()
xm=[]
ym=[]
#работа с канвасом(осн часть проги)
# СЧитать листбокс, для неотрицательных пойти по 3 циклам перебирая все варианты

    


