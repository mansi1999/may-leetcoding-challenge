"""
Check If It Is a Straight Line

You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.
Example 1:

Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true

Example 2:

Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false

Constraints:
  2 <= coordinates.length <= 1000
  coordinates[i].length == 2
  -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
  coordinates contains no duplicate point.
  
If there're only 2 points, return true.
Check if all other points lie on the line defined by the first 2 points.
Use cross product to check collinearity.
"""
class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        n = len(coordinates)
        if n==2:
            return True
        
        x1, y1, x2, y2 = coordinates[0][0], coordinates[0][1], coordinates[1][0], coordinates[1][1]
        
        if x1 == x2:
            for i in range(2,n):
                if coordinates[i][0]!=x1:
                    return False
                
        if y1 == y2:
            for i in range(2,n):
                if coordinates[i][1]!=y1:
                    return False
        
        else:
            m = (y2 - y1)/(x2 - x1)
            c = y1 - m*x1

            for i in range(2,n):
                if (coordinates[i][1] !=( m*coordinates[i][0] + c)):
                    return False
            
        return True
