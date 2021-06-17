while(1):
    register_check = input("\nDo you want to register (y/n) : ")
    if(register_check == 'y') :
        username = input("\nEnter your username : ")
        password = input("Enter your password : ")

        ##Password valid check##
        while(1) :
            password_length = len(password)
            count_upper,count_lower,count_numeric = 0,0,0
            for char in password :
                if(char.isupper()):
                    count_upper += 1
                elif(char.islower()):
                    count_lower += 1
                elif(char.isnumeric()):
                    count_numeric += 1
            if(count_upper and count_lower and count_numeric and password_length == 8):
                print("\nRegistered Successfully !!")
                break
            else :
                print("\nError : Enter a valid password !!\n")
                password = input("Enter your password : ")

        ##login check##
        while(1):
            login_check = input("\nDo you want to login (y/n) : ")
            if(login_check == 'y') :
                username_input = input("\nEnter your username : ")
                password_input = input("Enter your password : ")
                if(username_input != username or password_input != password):
                    print("\nEnter a valid username and password !!")
                else :
                    print("\nlogin successfully !!")
                    ##Use services ##
                    while(1):
                        service_check = input("\nDo you want to use our services (y/n) :")
                        if(service_check == 'y') :
                            print("\nWe provide three services :-")
                            print("1) Calculator (press c)")
                            print("2) Table generator (press t)")
                            print("3) Pattern print (press p)")

                            service_choice = input("\nEnter your choice : ")
                            if(service_choice == 'c'):
                                ##Calculator##
                                while(1):
                                    print("\n---Calculator---")
                                    n1 = eval(input("\nEnter first number : "))
                                    n2 = eval(input("Enter second number : "))
                                    print("\nWhich mathematical operation to perform")
                                    print("1) Addition (press a)")
                                    print("2) Substraction (press s)")
                                    print("3) Multiplication (press m)")
                                    print("4) Division (press d)")
                                    operation = input("\nEnter your choice :")
                                    if(operation == 'a'):
                                        print(n1,' + ',n2,' = ',n1+n2)
                                    elif(operation == 's'):
                                        print(n1,' - ',n2,' = ',n1-n2)                    
                                    elif(operation == 'm'):
                                        print(n1,' x ',n2,' = ',n1*n2)                
                                    elif(operation == 'd'):
                                        print(n1,' / ',n2,' = ',n1/n2)
                                    exit_choice = input("\nDo you want to exit calculator (y/n) :")
                                    if(exit_choice == 'y'):
                                        break
                                    
                                                  
                            if(service_choice == 't'):
                               ##Table Generator##
                               while(1):
                                   print("\n---Table Generator---")
                                   n = eval(input("\nEnter the number : "))
                                   for i in range(1,11):
                                       print(n,' x ',i,' = ',n*i)
                                   exit_choice = input("\nDo you want to exit table generator (y/n) : ")
                                   if(exit_choice == 'y'):
                                       break

                       
                            if(service_choice == 'p'):
                                ##pattern printing ##
                                while(1):
                                    print("\n---Pattern Printing---")
                                    n = eval(input("\nEnter the number : "))
                                    for i in range(1,n+1):
                                        for j in range(1,i+1):
                                            print(j,end='')
                                        print()
                                    exit_choice = input("\nDo you want to exit pattern printing (y/n) : ")
                                    if(exit_choice == 'y'):
                                       break

                        else :
                            break
            else:
                break
    else:
        break

   
            
            
    
             
                 
    





