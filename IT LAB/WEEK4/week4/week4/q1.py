class sub:
    def f1(self, s1):
        return self.f2([], sorted(s1))
    def f2(self, curr, s1):
        if s1:
            return self.f2(curr,s1[1:]) + self.f2(curr + [s1[0]], s1[1:])
        return [curr]
a=[]
n=map(int,input("enter a list of elements:\n").split())
print(sub().f1(n))