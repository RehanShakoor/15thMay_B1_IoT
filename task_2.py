s = input("Enter your string : ")
d = {i:s.count(i) for i in s}
d_length = len(d)
d_value = list(d.values())
d_max = max(d_value)
d_new = [d_max - d_value[i] for i in range(d_length)]


if(d_new.count(0)==d_length or d_new.count(0)==1):
    print("My String")

else:
    print("Not my string")




