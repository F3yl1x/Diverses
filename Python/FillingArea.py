class Area(object):
    def __init__(self, map):
        self.map = map

    def get_point(self, x, y):
        for found_y, row in enumerate(self.map):
            if found_y != y:
                continue
            for found_x, cell in enumerate(row):
                if found_x == x:
                    return cell

    def set_point(self, x, y, value=0):
        self.map[y][x] = value


class AreaHelper(object):
    @staticmethod
    def fill_area(area: Area) -> Area:
        
        point_in_area = AreaHelper.findArea(area)

        if(Area.get_point(area,point_in_area[0],point_in_area[1]) == 0):
            Area.set_point(area,point_in_area[0],point_in_area[1],1)
            AreaHelper.fill(area,[point_in_area[0]+1,point_in_area[1]])
            AreaHelper.fill(area,[point_in_area[0],point_in_area[1]+1])
            AreaHelper.fill(area,[point_in_area[0]-1,point_in_area[1]])
            AreaHelper.fill(area,[point_in_area[0],point_in_area[1]-1])
        return area

    def fill(area: Area, point_in_area: tuple[int,int]):
        if(Area.get_point(area,point_in_area[0],point_in_area[1]) == 0):
            Area.set_point(area,point_in_area[0],point_in_area[1],1)
            AreaHelper.fill(area,[point_in_area[0]+1,point_in_area[1]])
            AreaHelper.fill(area,[point_in_area[0],point_in_area[1]+1])
            AreaHelper.fill(area,[point_in_area[0]-1,point_in_area[1]])
            AreaHelper.fill(area,[point_in_area[0],point_in_area[1]-1])

    def findArea(area: Area) -> tuple[int,int]:
        if(Area.get_point(area,0,0) == 1):
            return [1,1]
        
        for found_x, row in enumerate(area.map):
            for found_y, cell in enumerate(row):
                if (Area.get_point(area,found_x,found_y) == 1):
                    print(found_x+1,found_y+1)
                    return[found_x+1,found_y+1]
                
        


Test1 = Area([
[0, 0, 0, 0, 0, 0, 0, 0],
[0, 0, 0, 1, 1, 1, 1, 0],
[0, 1, 1, 1, 1, 1, 1, 0],
[0, 1, 1, 1, 1, 1, 1, 0],
[0, 1, 0, 0, 0, 0, 1, 0],
[0, 1, 0, 0, 0, 0, 1, 0],
[0, 1, 1, 1, 1, 1, 1, 0],
[0, 0, 0, 0, 0, 0, 0, 0]
])
print(Area.get_point(Test1,0,0))
Area.set_point(Test1,0,0,1)
print(Area.get_point(Test1,0,0))
Area.set_point(Test1,0,0)
print(Area.get_point(Test1,0,0))

AreaHelper.fill_area(Test1)
print("Nach Fill: ")
print(Area.get_point(Test1,5,5))
print(Area.get_point(Test1,4,4))