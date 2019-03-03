# Нарисовать заштрихованную фигуру, затем ее переместитть, промасштабировать
# и повернуть. Кардиоида ( ее уравнение х = acost(1 + cost); y = asint(1 + cost)
# a > 0; t принадлежит от 0 до 2п включая границы
#
#
#

import os
from tkinter import *
from tkinter import messagebox
from math import sqrt, acos, pi, cos, sin


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


root = Tk()
root.title('Построение треугольника с максимальным углом между высотой и биссектрисой')
root.geometry('1610x900')
WORK_PATH=os.path.abspath(os.getcwd())
bg_image=PhotoImage(file=os.path.join(WORK_PATH,'фон4.PNG'))
bg=Label(root,image=bg_image)

C = Canvas(root,width=1050,height=650,bg='white')
C.place(x=10,y=10)


# Построение кардиоиды

a = 50
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

print(i)
print(triangle[5])
while (i < triangle[5]):
    C.create_line((triangle[0] - x_i), i, triangle[0] + x_i, i)
    i += a / 2
    x_i += a * razn / 2

print(triangle)
C.create_polygon(x_y, fill = "white", outline = "black")

#C.create_oval(triangle[0], triangle[1], triangle[0] + 3, triangle[1] + 3)


ent1 = Entry(width=20)
ent1.place(x=1100,y=110)

l = Label(root,text='введите координаты: ',bg = "#426084",\
          fg = "white", font=("Helvetica", 16)).place(x=1300,y = 140)

ent2 = Entry(width=20)
ent2.place(x=1100,y=410)

ent3 = Entry(width=20)
ent3.place(x=1100,y=610)


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
