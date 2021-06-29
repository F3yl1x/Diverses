class ClimbingStairs:
    moeglichkeiten = 0

    def climbing_stairs(number_of_stairs: int) -> int:
        if(number_of_stairs <= 1):
            return 1
        elif(number_of_stairs == 2):
            return 2
        elif():
            ClimbingStairs:merker(1,moeglichkeiten,number_of_stairs)
            merker(2,moeglichkeiten,number_of_stairs)
            return moeglichkeiten

    def merker(number_s,moeglichkeiten,steps):
        if(number_s +1 <= steps):
            moeglichkeiten +1
            return
        elif(number_s + 2 == steps):
            moeglichkeiten +1
            return
        elif():
            merker(1,moeglichkeiten,steps)
            merker(2,moeglichkeiten,steps)

class1 = ClimbingStairs()
print(class1.climbing_stairs(3))