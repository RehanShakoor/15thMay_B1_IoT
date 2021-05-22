##Q1##
print('\n---Q1 (print even numbers) ---\n')
numbers = [386, 462, 47, 418, 907, 344, 236, 375, 823,
           566, 597, 978, 328, 615, 953, 345, 399, 162,
           758, 219, 918, 237, 412, 566, 826, 248, 866,
           950, 626, 949, 687, 217, 815, 67, 104, 58,
           512, 24, 892, 894, 767, 553, 81, 379, 843,
           831, 445, 742, 717, 958,743, 527]

print('Even number in the given list : ',end='')
for num in numbers :
    if(num == 237) :
        break
    elif(not num%2) :
        print(num,end=' ')
        
              

##Q2##
print('\n\n---Q2 (set containing colours from color_list_1 which are not present in color_list_2) ---\n')
color_list_1 = set(["White", "Black", "Red"])
color_list_2 = set(["Red", "Green"])
answer_set = set({})
for color in color_list_1 :
    if(not color in color_list_2) :
        answer_set.add(color)
print('Output set : ',end='')       
print(answer_set)

##Q3##
print('\n---Q3 (check pangram) ---\n')
input_string = input('Enter string for checking Pangram : ')
char_set = {i for i in input_string if i.isalpha()}
if(len(char_set) == 26):
    print(input_string,', is a Pangram')
else :
    print(input_string,', is not a Pangram')

##Q4##
print('\n---Q4 (computes the value of n+nn+nnn) ---\n')
n = input('Enter value of n : ')
ans = 0
for i in range(1,4):
    ans += int(n*i)
print('Answer : ',ans)

##Q5##
print('\n---Q5 (generate the corresponding two integer list) ---\n')
input_string = input('Enter the string in required fashion : ')
input_list = input_string.split('#')
list_1 = input_list[0].split()
list_2 = input_list[1].split()
list_1 = [int(i) for i in list_1]
list_2 = [int(i) for i in list_2]

print('list 1 : ',list_1)
print('list 2 : ',list_2)

##Q6##
print('\n---Q6 (sorting alphabetically) ---\n')
input_string = input('Enter comma separated sequence of words : ')
input_list = input_string.split(',')
input_list.sort()
output_string = ''
for i in input_list :
    output_string += i + ','
output_string.strip(',')
print('Words after sorting alphabetically : ',output_string)

##Q7##
print('\n---Q7 (student with max marks) ---\n')
d = {'Student': ['Rahul', 'Kishore', 'Vidhya', 'Raakhi'],
     'Marks': [57,87,67,79]}

marks_list = d['Marks']
max_marks = max(marks_list)
max_marks_index = marks_list.index(max_marks)

student_list = d['Student']
print('Student with maximum marks : ',student_list[max_marks_index])

##Q8##
print('\n---Q8 (number of letters and digits) ---\n')
input_string = input('Enter a sentence : ')
letter_count ,digits_count = 0,0 
for i in input_string :
    if(i.isalpha()):
        letter_count += 1
    elif(i.isnumeric()):    
        digits_count += 1

print('LETTER ',letter_count)
print('DIGITS ',digits_count)
        
##Q9##
print('\n---Q9 (creates a new dictionary of students) ---\n')

d = {'Name': ['Akash', 'Soniy', 'Vishakha','Akshay', 'Rahul', 'Vikas'],
'Subject': ['Python', 'Java', 'Python', 'C', 'Python', 'Java'],
'Ratings': [8.4, 7.8, 8, 9, 8.2, 5.6]}

newData = {'Name' : [],'Ratings' : []}
index = 0
for sub in d['Subject']:
    if(sub == 'Python'):
        newData['Name'].append(d['Name'][index])
        newData['Ratings'].append(d['Ratings'][index])
    index += 1 

print('new dictionary of students : ',newData)


##Q10##
print('\n---Q10 (class with a generator) ---\n')
class generator_class :
    def __init__(num,n):
        num.n = n
  
    def generator_function(num) :
        for i in range(0,num.n + 1):
            if(not i%7):
                yield i
n = int(input('Enter the value of n : '))
gen = generator_class(n)
gen_list = list(gen.generator_function())
print('List of numbers divisible by 7 in the range 0 and ',n,' = ',gen_list)


##Q11##
print('\n---Q11 (trace of robot movement) ---\n')
up = eval(input('UP : '))
down = eval(input('DOWN : '))
left = eval(input('LEFT : '))
right = eval(input('RIGHT : '))

net_up = abs(up - down)
net_right = abs(right - left)

total_distance = (net_up**2 + net_right**2)**0.5

print('distance = ',round(total_distance))
        







