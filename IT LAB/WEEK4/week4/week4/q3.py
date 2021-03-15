class Poww:
    def poww(self,a, b):
        res=a**b
        return res

x=int(input("enter number x\n"))
n=int(input("enter number n\n"))
ob=Poww()
print("pow(",x,",",n,") : ",ob.poww(x,n))
