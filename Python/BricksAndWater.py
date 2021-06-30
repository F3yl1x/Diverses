class BricksAndWaterPython:


    def how_much_water(bricks_array: list) -> int:
        wasser = 0
        laenge = len(bricks_array)
     
        for i in range(1, laenge - 1) :
         
            links = bricks_array[i]
            for z in range(i) :
                links = max(links, bricks_array[z])
         
            rechts = bricks_array[i]
         
            for z in range(i + 1 , laenge) :
                rechts = max(rechts, bricks_array[z])
             
            wasser = wasser + (min(links, rechts) - bricks_array[i])
 
        return wasser



bricksArray1 = [2,0,2]
bricksArray2 = [1,0,2,1]
bricksArray3 = [2,0,3,0,2]
bricksArray4 = [5, 0, 2, 5, 6, 5]
bricksArray5 = [1,0,1]


print("Wasser: ",BricksAndWaterPython.how_much_water(bricksArray1))