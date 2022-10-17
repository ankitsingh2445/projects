from tkinter import *
root=Tk()

root.iconbitmap("D:\intern project/24.ico")

root.geometry("800x800")
root.configure(background="#758AA2")
e=Entry(root,font=36)
e.configure(background="#99AAAB")

e.place(x=600,y=340,height=60,width=240)
n=Entry(root,font=36)

n.place(x=600,y=180,height=60,width=240)
n.configure(background="#758AA2")



# equivalent resistance caclulation


r=[]
q=0
def sub(): # CALCULATING SERIES RESISTENCE
    global r,q

    r.append(e.get())
    e.delete(0, END)
    a=0
    for i in range(len(r)):

        a+=float(r[i])
        print(a)
        q=a
    n.delete(0, END)
    n.insert(0,q)

def pl():   # CALCULATING PARALLEL RESISTANCE
    global r,q

    r.append(e.get())
    e.delete(0, END)
    a=0
    for i in range(len(r)):
        r[i]=float(r[i])
        a=a+1/r[i]
        print(a)
        q=1/a
    n.delete(0, END)
    n.insert(0,q)

def clear():
    r.clear()
    e.delete(0, END)



myButton=Button(root,text="SERIES",width=10,height=5,command=sub,bg="#6A89CC")


myButton.place(x=380,y=600)
myButton=Button(root,text="PARREL",width=10,height=5,command=pl,bg="#6A89CC")


myButton.place(x=480,y=600)
myButton=Button(root,text="CA",width=10,height=5,command=clear,bg="#FF3E4D")
myButton.place(x=280,y=600,)
voltage=0


# resistance calculation


def vlt():  # GETTING VOLATGE VALUE
    global voltage

    voltage=e.get()

    voltage=float(voltage)
current=0
def curr():   # GETTING CURRENT VALUR
    global current

    current=e.get()
    current=float(current)
resi=0
def resistence_calculation():   # CALCULATING RESISTANCE
    global resi
    resi=float(voltage/current)
    n.delete(0,END)
    n.insert(0,resi)






myButton=Button(root,text="voltage",width=10,height=5,command=vlt,bg="#6A89CC")
myButton.place(x=580,y=600)
myButton=Button(root,text="current",width=10,height=5,command=curr,bg="#6A89CC")
myButton.place(x=680,y=600)
myButton=Button(root,text="R ?",width=10,height=5,command=resistence_calculation,bg="#67E6DC")
myButton.place(x=880,y=600)
myButton=Button(root,text="QUIT",width=18,height=4,command=root.quit,bg="#F9DDA4")
myButton.place(x=655,y=460)




#CALCULATION OF CURRENR


ragi=0
def regi(): # getting resistence value
    global ragi
    #vi1.delete(0,END)
    ragi=e.get()
    ragi=float(ragi)
curri=0
def current_calculation(): # CALCULATING CURRENT
    global curri
    curri=float(voltage/ragi)
    n.delete(0,END)
    n.insert(0,curri)
myButton=Button(root,text="C ?",width=10,height=5,command=current_calculation,bg="#67E6DC")
myButton.place(x=980,y=600)
myButton=Button(root,text="ressiancte",width=10,height=5,command=regi,bg="#6A89CC")
myButton.place(x=780,y=600)




# voltage caclulation


pot=0

def voltage_calculation():  # CALCULATING VOLATGE
    global pot
    pot=((current)*(ragi))
    n.delete(0, END)
    n.insert(0, pot)
myButton=Button(root,text="V ?",width=10,height=5,command=voltage_calculation,bg="#67E6DC")
myButton.place(x=1080,y=600)

root.mainloop()