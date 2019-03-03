# 1 Лабораторная работа по КГ
# На плоскости дано множество точек. Найти такой треугольник,
#
#
#
#
#
from tkinter import *
 
 
# удаление выделенного элемента
def delete():
    selection = languages_listbox.curselection()
    # мы можем получить удаляемый элемент по индексу
    # selected_language = languages_listbox.get(selection[0])
    languages_listbox.delete(selection[0])
 
 
# добавление нового элемента
def add():
    new_language = language_entry.get()
    languages_listbox.insert(0, new_language)
 
root = Tk()
root.title("GUI на Python")

 
# текстовое поле и кнопка для добавления в список
language_entry = Entry(width=40)
language_entry.grid(column=0, row=0, padx=6, pady=6)
add_button = Button(text="Добавить", command=add).grid(column=1, row=0, padx=6, pady=6)
 
# создаем список
languages_listbox = Listbox()
languages_listbox.grid(row=1, column=0, columnspan=2, sticky=W+E, padx=5, pady=5)
 
# добавляем в список начальные элементы
languages_listbox.insert(END, "Python")
languages_listbox.insert(END, "C#")
 
delete_button = Button(text="Удалить", command=delete).grid(row=2, column=1, padx=5, pady=5)
 
root.mainloop()
'''
from tkinter import *

lang = ['python','C++','C#']
root = Tk()
root.title('Triangle')
root.geometry('400x400')
frame = Frame(root)
frame.grid()

ent = Entry(frame,width=20)
ent.grid(row=0,column=1,columnspan=70, padx=20, pady=30)

lstbox = Listbox()

for i in lang:
    lstbox.insert(END,i)
lstbox.place(x=20,y=80)
l = Label(text='Введите координаты точки')
l.grid(row=0,column=1)

but = Button(root,text='внести в список',width=20,height=1,bg='blue',fg='white')
but.place(x=170,y=50)

         



c = Canvas(root,width=200, height=200,bg = 'lightblue')

c.place(x=160,y=80)
root.mainloop()



# родительский элемент
root = Tk()
# устанавливаем название окна
root.title("Quadratic calculator")
# устанавливаем минимальный размер окна 
root.minsize(325,230)
# выключаем возможность изменять окно
root.resizable(width=True, height=True)
 
# создаем рабочую область
frame = Frame(root)
frame.grid()
 
# поле для ввода первого аргумента уравнения (a)
a = Entry(frame, width=3)
a.grid(row=1,column=1,padx=(10,0))
 
# текст после первого аргумента
a_lab = Label(frame, text="x**2+").grid(row=1,column=2)
 
# поле для ввода второго аргумента уравнения (b)
b = Entry(frame, width=3)
b.grid(row=1,column=3)
# текст после второго аргумента
b_lab = Label(frame, text="x+").grid(row=1, column=4)
 
# поле для ввода третьего аргумента уравнения (с)
c = Entry(frame, width=3)
c.grid(row=1, column=5)
# текст после третьего аргумента
c_lab = Label(frame, text="= 0").grid(row=1, column=6)
 
# кнопка решить
but = Button(frame, text="Solve").grid(row=1, column=7, padx=(10,0))
 
# место для вывода решения уравнения
output = Text(frame, bg="lightblue", font="Arial 12", width=35, height=10)
output.grid(row=2, columnspan=8)
 
# запускаем главное окно
root.mainloop()
'''

