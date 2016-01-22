from threading import Thread, Lock

i = 0
lock = Lock()

def add():
    global i
    for x in range(0,1000000):
        lock.acquire()
        i += 1
        lock.release()

def sub():
    global i
    for x in range(0,1000000):
        lock.acquire()
        i -= 1
        lock.release()

def main():

    adder_thr1 = Thread(target = add)
    adder_thr1.start()

    minus_thr2 = Thread(target = sub)
    minus_thr2.start()

    adder_thr1.join()
    minus_thr2.join()

    print("The sum is:", i)

main()
