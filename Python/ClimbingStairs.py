class ClimbingStairs:
    moeglichkeiten = 0

    def merker(treppen,punkt):
        if(treppen - punkt == 1):
            ClimbingStairs.moeglichkeiten += 1
            return
        if(treppen - punkt == 2):
            ClimbingStairs.moeglichkeiten += 1
            return
        if(treppen - punkt >= 3):
            ClimbingStairs.merker(treppen,punkt+1)
            ClimbingStairs.merker(treppen,punkt+2)

    @staticmethod
    def climbing_stairs(number_of_stairs: int) -> int:
        if(number_of_stairs <= 0):
            return 0
        ClimbingStairs.merker(number_of_stairs,0)
        ClimbingStairs.merker(number_of_stairs,1)

        return ClimbingStairs.moeglichkeiten


print(ClimbingStairs.climbing_stairs(35))