def get_pascals_triangle_row(row_number: int) -> list:
    
    dreieck = [1]
    dreieckPrev = [1]

    if(row_number < 0 ):
        dreieck.clear()
        return(dreieck)

    if(row_number == 0):
        return(dreieck)

    if(row_number == 1):
        dreieck.insert(0,1)
        return(dreieck)

    dreieck.insert(0,1)
    for i in range(row_number-1):
        dreieckPrev = [1,1]

        for z in range(0,len(dreieck)-1):
            dreieckPrev.insert(z+1,dreieck[z]+dreieck[z+1])
        
        dreieck = dreieckPrev


    return dreieck


#Treibercode
print("-1: ", get_pascals_triangle_row(-1))
print("0: ", get_pascals_triangle_row(0))
print("1: ", get_pascals_triangle_row(1))
print("2: ", get_pascals_triangle_row(2))
print("3: ", get_pascals_triangle_row(3))
print("4: ", get_pascals_triangle_row(4))
print("10: ", get_pascals_triangle_row(10))
