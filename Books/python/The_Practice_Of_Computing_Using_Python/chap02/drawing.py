# using module tutrle to draw graphs
import turtle

# Draw a 5-pointed star
def star(size):
    turtle.forward(size)
    turtle.right(144)
    turtle.forward(size)
    turtle.right(144)
    turtle.forward(size)
    turtle.right(144)
    turtle.forward(size)
    turtle.right(144)
    turtle.forward(size)

# Draw a rectangle
def rectangle(length,width):
    turtle.forward(length)
    turtle.right(90)
    turtle.forward(width)
    turtle.right(90)
    turtle.forward(length)
    turtle.right(90)
    turtle.forward(width)

# Draw a triangle
def triangle(size):
    turtle.right(60)
    turtle.forward(size)
    turtle.right(120)
    turtle.forward(size)
    turtle.right(120)
    turtle.forward(size)

triangle(100)
rectangle(100, 100)
star(100)
