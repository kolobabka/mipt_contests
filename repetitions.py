from num2dac import num2dac
from DAC     import *
import time

DELAY = 0.005


def repeat(repetitionsNumber):
    
    for x in range(repetitionsNumber):    
        for i in range(0, 256):
            byte = num2dac(i)
            time.sleep(DELAY)
        for i in range(255, -1, -1):
            byte = num2dac(i)
            time.sleep(DELAY)

def main():
    initGpio()
    while True:
        try:
            print("Введите число повторений: ", end="")
            repetitionsNumber = int(input())
        except ValueError:
            print("Некорректное число повторений, введите снова")
            continue
        except KeyboardInterrupt:
            print("Спасибо за использование")
            resetGpio()
            quit()
        break
    repeat(repetitionsNumber)
    resetGpio()

if __name__ == "__main__":
    main()