class Pair:
    def pairs(self):
        flag=0
        a=input("enter a list of numbers\n").split(' ')
        targ=int(input("enter target value:\n"))
        print("the pairs are:")
        for i in range(len(a)):
            for j in range(i+1,len(a)):
                if(int(a[i])+int(a[j])==targ):
                    flag=1
                    print(i,",",j)
        if(flag==0):
            print("no such pair exists")

ob=Pair()
ob.pairs()


