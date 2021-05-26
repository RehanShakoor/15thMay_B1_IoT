def magic_square_generator(n):
    
    magic_square = [[0 for i in range(n)] for i in range(n)]

    i = int(n/2)
    j = int(n-1)
    magic_square[i][j] = 1

    for num in range(2,n*n+1):
        i -= 1
        j += 1
        
        if(i < 0 and (j < n and j >= 0) ):
            i = n-1

        elif(i >= n and (j < n and j >= 0) ):
            i = 0       
            
        if(j >= n and (i >= 0 and i < n)):
            j = 0
            
        elif(j < 0 and (i >= 0 and i < n)):
            j = n-1
            
        if(i < 0 and j >= n):
            i = 0
            j = n-2
            
        while(magic_square[i][j] != 0):
            j -= 2
            i += 1 
            
            if(i < 0 and (j < n and j >= 0) ):
                i = n-1

            elif(i >= n and (j < n and j >= 0) ):
                i = 0       
                
            if(j >= n and (i >= 0 and i < n)):
                j = 0
                
            elif(j < 0 and (i >= 0 and i < n)):
                j = n-1
                
            if(i < 0 and j >= n):
                i = 0
                j = n-2
              
            
        magic_square[i][j] = num

    for j in magic_square:
        for i in j:
            print(i,end=' ')
        print(end='\n')


n =int(input('Enter the value of n : '))
magic_square_generator(n)
    
