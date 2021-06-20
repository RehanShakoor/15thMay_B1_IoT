from math import *

def addition():
    while(1):
        print("\nAddition ")
        num1=int(input("Enter num1 = "))
        num2=int(input("Enter num2 = "))
        print("{} + {} = {}\n".format(num1,num2,num1+num2))
        choice=input("Continue addition (y/n) : ")
        if(choice=='n'):
            break

def substraction():
    while(1):
        print("\nSubstraction")
        num1=int(input("Enter num1 = "))
        num2=int(input("Enter num2 = "))
        print("{} - {} = {}\n".format(num1,num2,num1-num2))
        choice=input("Continue substraction (y/n) : ")
        if(choice=='n'):
            break

def multiplication():
    while(1):
        print("\nMultiplication")
        num1=int(input("Enter num1 = "))
        num2=int(input("Enter num2 = "))
        print("{} x {} = {}\n".format(num1,num2,num1*num2))
        choice=input("Continue multiplication (y/n) : ")
        if(choice=='n'):
            break

def division():
    while(1):
        print("\nDivision")
        num1=int(input("Enter num1 = "))
        num2=int(input("Enter num2 = "))
        print("{} / {} = {}\n".format(num1,num2,num1/num2))
        choice=input("Continue division (y/n) : ")
        if(choice=='n'):
            break

def basicCalculator():
    while(1):
        print("\nBasic calculator")
        print("Following functionality is provided in basic calculator")
        print("a) Addition")
        print("b) Substraction")
        print("c) Multiplication")
        print("d) Division")
        print("e) Exit basic calculator")
        choice=input("Enter your choice : ")
        if(choice=='a'):
            addition()
        elif(choice=='b'):
            substraction()
        elif(choice=='c'):
            multiplication()
        elif(choice=='d'):
            division()
        elif(choice=='e'):
            print("Exited from basic calculator\n")
            break

def trigonometry():
    while(1):
        print("\nTrigonometry")
        print("Following functionality is provided in trigonometry")
        print("a) sin(\u03B8)")
        print("b) cos(\u03B8)")
        print("c) tan(\u03B8)")
        print("d) cosec(\u03B8)")
        print("e) sec(\u03B8)")
        print("f) cot(\u03B8)")
        choice=input("Enter your choice : ")
        if(choice=='a'):
            print("\nsin(\u03B8)")
            angle=int(input("Enter angle in degrees = "))
            print("sin({}) = {}".format(angle,sin(radians(angle))))
        elif(choice=='b'):
            print("\ncos(\u03B8)")
            angle=int(input("Enter angle in degrees = "))
            print("cos({}) = {}".format(angle,cos(radians(angle))))
        elif(choice=='c'):
            print("\ntan(\u03B8)")
            angle=int(input("Enter angle in degrees = "))
            print("tan({}) = {}".format(angle,tan(radians(angle))))
        elif(choice=='d'):
            print("\ncosec(\u03B8)")
            angle=int(input("Enter angle in degrees = "))
            print("cosec({}) = {}".format(angle,1/sin(radians(angle))))
        elif(choice=='e'):
            print("\nsec(\u03B8)")
            angle=int(input("Enter angle in degrees = "))
            print("sec({}) = {}".format(angle,1/cos(radians(angle))))
        elif(choice=='f'):
            print("\ncot(\u03B8)")
            angle=int(input("Enter angle in degrees = "))
            print("cot({}) = {}".format(angle,1/tan(radians(angle))))
        choice=input("\nContinue trigonometry (y/n) : ")
        if(choice=='n'):
            break    


def power():
    while(1):
        print("\ny to the power x")
        x=int(input("Enter x = "))
        y=int(input("Enter y = "))
        print("{} to the power {} = {}".format(y,x,pow(x,y)))
        choice=input("\nContinue y to the power x (y/n) : ")
        if(choice=='n'):
            break

def logarithm():
    while(1):
        print("\nLogarihtm")
        base=int(input("Enter base = "))
        arg=int(input("Enter argument = "))
        print("log{} base{} = {}".format(arg,base,log(arg,base)))
        choice=input("\nContinue logarithm (y/n) : ")
        if(choice=='n'):
            break
                
def scientificCalculator():
    while(1):
        print("\nScientific calculator")
        print("Following functionality is provided in scientific calculator")
        print("a) Trignometric ratios")
        print("b) y to the power x")
        print("c) Logarithm")
        print("d) Exit scientific calculator")
        choice=input("Enter your choice : ")
        if(choice=='a'):
            trigonometry()
        elif(choice=='b'):
            power()
        elif(choice=='c'):
            logarithm()
        elif(choice=='d'):
            print("Exited from scientific calculator\n")
            break

while(1):
    print("Calculator")
    print("Following functionality is provided in calculator")
    print("a) Basic calculator")
    print("b) Scientific calculator")
    print("c) Exit calculator")
    choice=input("Enter your choice : ")
    if(choice=='a'):
        basicCalculator()
    elif(choice=='b'):
        scientificCalculator()
    elif(choice=='c'):
        print("Exited from calculator")
        break
