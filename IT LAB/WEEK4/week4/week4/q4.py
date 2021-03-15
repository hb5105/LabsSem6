class Strings:
    def get_String(self):
        a=input("enter a string:\n")
        return a
    def put_String(self,a):
        a=a.upper()
        print("the uppercase string is: ",a)
ob=Strings()   
ob.put_String(ob.get_String())

