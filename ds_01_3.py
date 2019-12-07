def binarysearch(l,k,length):
    low=0
    high=length-1
    while low<=high:
        mid=(low+high)//2
        if k<l[mid]:
            high=mid-1
        if k>l[mid]:
            low=mid+1
        if k==l[mid]:
            return mid+1
    else:
        return 0
k=int(input("请输入序列的元素个数"))
str1=input("请输入序列，以空格隔开")
l=[]
x = str1.split(" ");
for i in range(k):
       m=(int(x[i]))
       l.append(m)
q=int(input("请输入待查找的数"))
print(binarysearch(l,q,k))


