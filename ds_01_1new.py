k=int(input())
str1=input()
L=[]
x = str1.split(" ");
for i in range(k):
       m=(int(x[i]))
       L.append(m)
#定义函数
def optimized_method_of_exhaustion(lst):
    length = len(lst)
    this_sum = max_sum = 0
    i=0
    while lst[i]<0:
        i=i+1
        if i==length:
            return 0
    for i in range(length):
        this_sum = 0
        for j in range(i, length):
            this_sum += lst[j]
            if this_sum > max_sum:
                max_sum = this_sum
    return max_sum
#调用函数
print(optimized_method_of_exhaustion(L))


