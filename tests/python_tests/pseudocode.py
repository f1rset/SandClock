import time
import math

#Pseudocode!

class SandClock:
    def __init__(self, timer : int, display_prop:tuple) -> None:
        
        self.begin_time = time.time() # Момент старту
        self.timer = timer
        
        #розрахунок кількості пікселів яка має впасти за одну секунду
        self.pixels_per_second = self.DeterminePixelsPerFall(display_prop, timer)
        
        
        self.current_angle = self.GetAccelerometerAngle((0, 0, 0)) 
        #                                                   |
        #                                                   V
        # замість (0, 0, 0) потрібно вектор з акселерометра
        self.local_display = self.GenerateGrid(display_prop)

    
    def GenerateGrid(self, props):
        result = []
        for cloumn in range(props[0]):
            temp = []
            for row in range(props[1]):
                temp.append(0)
            result.append(temp)
        return result
    def DeterminePixelsPerFall(display, timer : tuple) -> int:
        #розрахунок скільки пікселів припадає на одну секунду
        return timer / (display[0]+display[1])
    
    def ChangeLocalPixel(self, coords):
        value = self.local_display[coords[0]][coords[1]]
        if value == 0:
            self.local_display[coords[0]][coords[1]] = 0
        else:
            self.local_display[coords[0]][coords[1]] = 1

    def ChnagePixel(self, coords : tuple):
        #Змінити піксель на дисплеї
        #Використовуючи бібліотеку для роботи з дисплеєм від Nokia
        
        
        #також міняємо відповідний піксель у локальній версії дисплею
        self.ChangeLocalPixel(coords)
    
    def DetermineTimePassed(self):
        
        current_time = time.time() # час на момент запиту
        
        return current_time - self.begin_time
    
    def GetAccelerometerAngle(self):
        
        #дістати вектор з акселерометра
        #           |
        #           V
        vector = (0, 1, 1)
        
        x = vector[0]
        y = vector[1]
        z = vector[2]
        # через мат формулу порахувати нахил спочатку в
        # радіанах, матоім через arctang вернути в градуси
        # !!!це формула для 2д повертання, адже третя вісь нас не цікавить
        return math.atan(x/(math.sqrt(y**2 + z**2)))
    
    def DeleteSand(self, amount):
        #видаляє пісок відповідно до кількості часу який пройшов
        #Видаляє з локального дисплею!
        pass
    
    def SandFall(self):
        #коду не буде, проте

        #1. потрібно пройтися по кожному пікселю
        # зверху вних, та якщо він 1, то перевіряємо
        # чи йому є куди впасти
        # перевірку на місця для падіння робимо зважаючи на 
        # кут нахилу, а саме:
        # перевіряти будемо nxn пікселів, з потрібним у середині
        # перевіряти будемо. нахилом також визначається в якому порядку
        # перебираються пікселі

        #2. пікселі завжди перебираються знизу до верху, де низом буде та сторона яка дивиться в ділогу
        # тому що в такий спосіб складність буде O(n), адже кожен піксель перевіриться тільки один раз
        pass
    def render(self):
        #виводить змінену локальну версію дисплею 
        #на фізичний дисплей
        pass
    def Update(self):
        time_passed = self.DetermineTimePassed()
        
        if time_passed * self.pixels_per_second < 2:
            #якщо падає менше ніж два пікселі, то
            # адейт не відбуваєьбся
            return None
        
        
        self.degree += self.GetAccelerometerAngle((0, 4, 2))
        #                                |
        #                                V
        #взяти з акселерометра останній нахил
        
        #змінює локальний дисплей
        self.SandFall()
        
        #виводить змінений локальний дисплей
        #на фізичний дисплей
        self.render()
        
