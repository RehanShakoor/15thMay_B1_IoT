class String():

    def __init__(self,data):
        self.data = data
    def __del__(self):
        print('Deleted')

    
    def __sub__(self,obj):
        for i in obj.data:
            
            if(i in self.data):
                n = len(self.data)
                ind = self.data.index(i)
                self.data = self.data[:ind:]+self.data[ind+1::]

        return self.data        

input_1 = input("Enter first string : ")
input_2 = input("Enter second string : ")
s1 = String(input_1)
s2 = String(input_2)
print("difference (first string - second string) = ",s1-s2)
            
            
        
