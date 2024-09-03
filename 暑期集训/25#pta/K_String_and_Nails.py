from math import fabs  
  
class X:  
    def __init__(self, x=0, y=0, len=0, id=0):  
        self.x = x  
        self.y = y  
        self.length = len  # 在Python中，我们通常不使用len作为变量名，因为它会覆盖内置的len函数  
        self.id = id  
  
s = [X() for _ in range(200100)]  
sum_length = 0  
ok = True  
  
def cmp(e1, e2):  
    return e1.id > e2.id  
  
def run():  
    n = int(input())  
    cnt = n  
    for i in range(1, n + 1):  
        x, y = map(int, input().split())  
        s[i].x = x  
        s[i].y = y  
        s[i].length = x + y  
        sum_length += s[i].length  
      
    for i in range(1, n + 1):  
        s[i].id = fabs(cnt * s[i].length - sum_length)  
        cnt -= 1  
        sum_length -= s[i].length  
      
    s.sort(key=lambda x: x.id, reverse=True)  
      
    for i in range(3, n + 1):  
        if (s[i].y - s[i - 1].y) * (s[i].x - s[i - 2].x) == (s[i].x - s[i - 1].x) * (s[i].y - s[i - 2].y):  
            ok = False  
            break  
      
    if ok:  
        print("YES")  
        for i in range(1, n):  
            print(s[i].x, s[i].y)  
    else:  
        print("NO")  
  
if __name__ == "__main__":  
    run()