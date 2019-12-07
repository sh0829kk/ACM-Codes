k=int(input("请输入整数K"))
str1=input("请输入序列，以空格隔开")
L=[]
x = str1.split(" ");
for i in range(k):
       m=(int(x[i]))
       L.append(m)
#定义函数
def online_algorithm(lit):
    length=len(lit)
    this_sum=max_sum=0
    i=0
    while lit[i]<0:
        i=i+1
        if i==length:
            return 0
    for i in range(length):
        this_sum+=lit[i]
        if this_sum>max_sum:
            max_sum=this_sum
        elif this_sum<0:
            this_sum=0
    return max_sum
#调用函数
print(online_algorithm(L))


