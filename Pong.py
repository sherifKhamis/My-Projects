import turtle

window = turtle.Screen()
window.title("Pong")
window.setup(600, 600)
window.bgcolor("Black")
window.tracer(0)

paddle_A = turtle.Turtle()
paddle_A.speed(0)
paddle_A.shape("square")
paddle_A.shapesize(stretch_wid=5, stretch_len=1)
paddle_A.color("white")
paddle_A.penup()
paddle_A.goto(-250, 0)

paddle_B = turtle.Turtle()
paddle_B.speed(0)
paddle_B.shape("square")
paddle_B.shapesize(stretch_wid=5, stretch_len=1)
paddle_B.color("white")
paddle_B.penup()
paddle_B.goto(250, 0)

Ball = turtle.Turtle()
Ball.speed(0)
Ball.shape("square")
Ball.color("white")
Ball.penup()
Ball.goto(0, 0)
Ball.dx = 0.05
Ball.dy = 0.05


def paddle_A_up():
    y = paddle_A.ycor()
    y += 20
    paddle_A.sety(y)

def paddle_A_down():
    y = paddle_A.ycor()
    y -= 20
    paddle_A.sety(y)

def paddle_B_up():
    y = paddle_B.ycor()
    y += 20
    paddle_B.sety(y)

def paddle_B_down():
    y = paddle_B.ycor()
    y -= 20
    paddle_B.sety(y)

window.listen()
window.onkeypress(paddle_A_up, "w")
window.onkeypress(paddle_A_down, "s")
window.onkeypress(paddle_B_up, "Up")
window.onkeypress(paddle_B_down, "Down")


while True:
    window.update()

    Ball.setx(Ball.xcor() + Ball.dx)
    Ball.sety(Ball.ycor() + Ball.dy)

    if Ball.ycor()> 290:
        Ball.sety(290)
        Ball.dy *= -1

    if Ball.ycor() < -290:
        Ball.sety(-290)
        Ball.dy *= -1

    if Ball.xcor() > 295:
       Ball.goto(0,0)
       Ball.dx *= -1

    if Ball.xcor() < -295:
       Ball.goto(0,0)
       Ball.dx *= -1

    if (Ball.xcor() > 250 and Ball.xcor() < 260) and (Ball.ycor() < paddle_B.ycor() +40 and Ball.ycor() > paddle_B.ycor() - 40):
        Ball.setx(250)
        Ball.dx *= -1

    if (Ball.xcor() < -240 and Ball.xcor() > -250) and (Ball.ycor() < paddle_A.ycor() +40 and Ball.ycor() > paddle_A.ycor() - 40):
        Ball.setx(-240)
        Ball.dx *= -1
