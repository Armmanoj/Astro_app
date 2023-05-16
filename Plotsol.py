import matplotlib.pyplot as plt
import numpy as np

def extract_points():
    x,y=[],[]
    with open ('sol.txt','r') as f:
        while (1):
            s=""
            c=f.read(1)
            if c=='': break
            while c!='A':
                s+=c;
                c=f.read(1)
            x.append(float(s))
            s=""
            c=f.read(1)
            while c!='B':
                s+=c;
                c=f.read(1)
            y.append(float(s))
    return x,y

def plot():
    X,Y=extract_points()
    x,y=np.array(X),np.array(Y)
    print("\n")
    plt.plot(x,y)
    plt.show()
    
plot()
