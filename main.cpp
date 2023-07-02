#include <GL/glut.h>
#include <math.h>
#include <string.h>
float sun_x_default = -0.005;
float sun_y_default =  -0.05;
float car_start_pos =  -0.005;
float cloud_1_defSpeed =  -0.005;
float cloud_2_defSpeed =  -0.005;
float cloud_3_defSpeed =  -0.005;
float def_carSpeed = 0.0002;
float def_carNightSpeed = 0.5;

float sunX = sun_x_default;
float sunY = sun_y_default;
float cloudOneSpeed = cloud_1_defSpeed;
float cloudTwoSpeed = cloud_2_defSpeed;
float cloudThreeSpeed = cloud_3_defSpeed;
float posOfSUN = 0;
float carSpeed = def_carSpeed;
float carPos = car_start_pos;
int lock=1;
int pause=0;
int mode=0;
void lockPosition() {
    float newPos;
    float newsunX;
    float newsunY;
    float newcarPos;
    float newCloudOneSpeed;
    float newCloudTwoSpeed;
    float newCloudThreeSpeed;
    if(lock==1) 
    {
        newPos = posOfSUN;
        newsunX = sunX;
        newsunY = sunY;
        newcarPos = carPos;
        newCloudOneSpeed = cloudOneSpeed;
        newCloudTwoSpeed = cloudTwoSpeed;
        newCloudThreeSpeed = cloudThreeSpeed;
        lock=2;

    } 
    else if(lock==2) 
    {
        posOfSUN = newPos;
        sunX = newsunX;
        sunY = newsunY;
        carPos = newcarPos;
        cloudOneSpeed = newCloudOneSpeed;
        cloudTwoSpeed = newCloudTwoSpeed;
        cloudThreeSpeed = newCloudThreeSpeed;
    }
    else if(lock==0)
        return;
}
void drawRectangle(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, GLfloat x4, GLfloat y4, float r, float g, float b) 
{
    glColor3f (r, g, b);
    glBegin(GL_QUADS);
        glVertex3f(x1, y1, 0.0f);  //Bottom-Left
        glVertex3f(x2, y2, 0.0f);  //Top-Left
        glVertex3f(x3, y3, 0.0f);  //Top-Right
        glVertex3f(x4, y4, 0.0f);  //Bottom-Right
    glEnd();
}
void drawBuilding(float wr,float wg,float wb)
{
    /*Building 1*/
     drawRectangle(0.12f, 0.05f, 0.12f, 0.19f, 0.2f, 0.19f, 0.2f, 0.05f, 1, 0.35, 0.69);
     for(float i=0.12; i<0.16; i+=0.02) {
        drawRectangle(0.14f, i, 0.14f, i+0.01, 0.155f, i+0.01, 0.155f, i, wr, wg, wb);
    }
    for(float i=0.12; i<0.16; i+=0.02) {
        drawRectangle(0.165f, i, 0.165f, i+0.01, 0.18f, i+0.01, 0.18f, i, wr, wg, wb);
    }
    /*Building 2*/
    drawRectangle(0.22f, 0.05f, 0.22f, 0.27f, 0.3f, 0.27f, 0.3f, 0.05f, 0.4, 0.4, 0.4);
    for(float i=0.12; i<0.24; i+=0.02) {
        drawRectangle(0.24f, i, 0.24f, i+0.01, 0.255f, i+0.01, 0.255f, i, wr, wg, wb);
    }
    for(float i=0.12; i<0.24; i+=0.02) {
        drawRectangle(0.265f, i, 0.265f, i+0.01, 0.28f, i+0.01, 0.28f, i, wr, wg, wb);
    }
    /*Building 3*/
     drawRectangle(0.32f, 0.05f, 0.32f, 0.33f, 0.4f, 0.33f, 0.4f, 0.05f, 1, 0.56, 0.33);
     for(float i=0.12; i<0.32; i+=0.02) {
        drawRectangle(0.34f, i, 0.34f, i+0.01, 0.355f, i+0.01, 0.355f, i, wr, wg, wb);
    }
    for(float i=0.12; i<0.32; i+=0.02) {
        drawRectangle(0.365f, i, 0.365f, i+0.01, 0.38f, i+0.01, 0.38f, i, wr, wg, wb);
    }
    /*Building 4*/
     drawRectangle(0.42f, 0.05f, 0.42f, 0.25f, 0.48f, 0.25f, 0.48f, 0.05f, 1.00, 0.13, 0.13);
      for(float i=0.12; i<0.23; i+=0.02) {
        drawRectangle(0.44f, i, 0.44f, i+0.01, 0.435f, i+0.01, 0.435f, i, wr, wg, wb);
    }
    for(float i=0.12; i<0.23; i+=0.02) {
        drawRectangle(0.445f, i, 0.445f, i+0.01, 0.46f, i+0.01, 0.46f, i, wr, wg, wb);
    }
    /*Building 5*/
    drawRectangle(0.5f, 0.05f, 0.5f, 0.29f, 0.58f, 0.29f, 0.58f, 0.05f, 0.56, 0.29, 1);
    for(float i=0.12; i<0.27; i+=0.02) {
        drawRectangle(0.52f, i, 0.52f, i+0.01, 0.535f, i+0.01, 0.535f, i, wr, wg, wb);
    }
    for(float i=0.12; i<0.27; i+=0.02) {
        drawRectangle(0.545f, i, 0.545f, i+0.01, 0.56f, i+0.01, 0.56f, i, wr, wg, wb);
    }
    /*Building 6*/
     drawRectangle(0.6f, 0.05f, 0.6f, 0.23f, 0.68f, 0.23f, 0.68f, 0.05f, 0.2, 0.5, 0.0);
     for(float i=0.12; i<0.20; i+=0.02) {
        drawRectangle(0.62f, i, 0.62f, i+0.01, 0.635f, i+0.01, 0.635f, i, wr, wg, wb);
    }
    for(float i=0.12; i<0.20; i+=0.02) {
        drawRectangle(0.645f, i, 0.645f, i+0.01, 0.66f, i+0.01, 0.66f, i, wr, wg, wb);
    }
}
void drawSky(float R, float G, float B) 
{
    drawRectangle(-0.05f, 0.09f, -0.05f, 0.40f, 0.85f, 0.40f, 0.85f, 0.09f, R, G, B);
}
void drawGrass(float R, float G, float B) 
{
    drawRectangle(-0.05f, -0.05f, -0.05f, 0.02f, 0.85f, 0.02f, 0.85f,-0.05f, R, G, B);
}
void drawRoad() 
{
    drawRectangle(-0.05f,0.02f, -0.05f,0.08f, 0.90f,0.08f, 0.90f,0.02f, 0.4, 0.4, 0.4);
    // Road stripes
    for(float i=-0.03f; i<0.80; i+=0.08) {
        drawRectangle(i,0.053f, i,0.057f, i+0.04,0.057f, i+0.04,0.053f, 0.7, 0.7, 0.7);
    }
    // Road edges top
    drawRectangle(-0.05f,0.08f, -0.05f,0.09f, 0.90f,0.09f, 0.90f,0.08f, 0.2, 0.2, 0.2);
    // Road edges bottom
    drawRectangle(-0.06f,0.02f, -0.05f,0.03f, 0.90f,0.03f, 0.90f,0.02f, 0.2, 0.2, 0.2);
}
void drawCircle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy) 
{
    glBegin(GL_POLYGON);
    for(int i=0; i<180; i++) {
        float angle = 4.0f * 3.1416f * i/180;
        float x = rx * cosf(angle);
        float y = ry * sinf(angle);
        glVertex2f((x+cx),(y+cy));
    }
    glEnd();
}
void drawClouds(float cloudR, float cloudG, float cloudB, float cloudA) {
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
    // Cloud 1
    glColor4f(cloudR, cloudG, cloudB, cloudA);
    drawCircle(0.025,0.025,cloudOneSpeed-0.01, 0.28);
    drawCircle(0.025,0.025,cloudOneSpeed-0.04, 0.28);
    drawCircle(0.025,0.025,cloudOneSpeed-0.07, 0.28);
    drawCircle(0.025,0.025,cloudOneSpeed-0.04, 0.30); 
    // Cloud 2
    drawCircle(0.025,0.025,cloudTwoSpeed-0.71, 0.32);
    drawCircle(0.025,0.025,cloudTwoSpeed-0.74, 0.32);
    drawCircle(0.025,0.025,cloudTwoSpeed-0.77, 0.32);
    drawCircle(0.025,0.025,cloudTwoSpeed-0.74, 0.34);
    // Cloud 3
    drawCircle(0.025,0.025,cloudThreeSpeed-0.41, 0.36);
    drawCircle(0.025,0.025,cloudThreeSpeed-0.44, 0.36);
    drawCircle(0.025,0.025,cloudThreeSpeed-0.47, 0.36);
    drawCircle(0.025,0.025,cloudThreeSpeed-0.44, 0.38);
    // Cloud 4
    drawCircle(0.025,0.025,cloudOneSpeed+0.12, 0.36);
    drawCircle(0.025,0.025,cloudOneSpeed+0.15, 0.36);
    drawCircle(0.025,0.025,cloudOneSpeed+0.18, 0.36);
    drawCircle(0.025,0.025,cloudOneSpeed+0.15, 0.38);
    // Cloud 5
    drawCircle(0.025,0.025,cloudTwoSpeed+0.42, 0.26);
    drawCircle(0.025,0.025,cloudTwoSpeed+0.45, 0.26);
    drawCircle(0.025,0.025,cloudTwoSpeed+0.48, 0.26);
    drawCircle(0.025,0.025,cloudTwoSpeed+0.45, 0.28);
    // Cloud 6
    drawCircle(0.025,0.025,cloudOneSpeed+0.62, 0.33);
    drawCircle(0.025,0.025,cloudOneSpeed+0.65, 0.33);
    drawCircle(0.025,0.025,cloudOneSpeed+0.68, 0.33);
    drawCircle(0.025,0.025,cloudOneSpeed+0.65, 0.35);
    glDisable(GL_BLEND);
}
void drawSun(float sunR, float sunG, float sunB) 
{
    glColor3f(sunR, sunG, sunB);
    drawCircle(0.0255, 0.02, sunX-0.05, sunY+0.3);
}

void drawCar1(int Scene) 
{
    drawRectangle(carPos-0.24,0.085, carPos-0.21,0.11, carPos-0.12,0.11, carPos-0.1,0.085, 0.56, 0.06, 0.11);
    drawRectangle(carPos-0.24,0.065, carPos-0.24,0.085, carPos-0.06,0.085, carPos-0.06,0.065, 0.56, 0.06, 0.11);
    if(Scene) 
    {
        drawRectangle(carPos-0.06,0.075, carPos-0.06,0.080, carPos+0.01,0.065, carPos-0.03,0.065, 0.9, 0.9, 0.0);
        glColor3f(0.9, 0.9, 0.0);
        drawCircle(0.05,0.007,carPos-0.0, 0.06);
    }    
    drawRectangle(carPos-0.23,0.085, carPos-0.21,0.105, carPos-0.195,0.105, carPos-0.195,0.085, 0.71, 0.84, 1);
    drawRectangle(carPos-0.19,0.085, carPos-0.19,0.105, carPos-0.15,0.105, carPos-0.15,0.085, 0.71, 0.84, 1);
    drawRectangle(carPos-0.145,0.085, carPos-0.145,0.105, carPos-0.125,0.105, carPos-0.11,0.085, 0.71, 0.84, 1);
    glColor3f(0.0,0.0,0);
    drawCircle(0.016,0.015,carPos-0.2, 0.06);
    drawCircle(0.016,0.015,carPos-0.1, 0.06); 
    glColor3f(0.8, 0.8, 0.8);
    drawCircle(0.008,0.007,carPos-0.2, 0.06);
    drawCircle(0.008,0.007,carPos-0.1, 0.06);
}
void drawEarlyMorning()
{
    drawGrass(0.10, 0.27, 0.11);
    drawSky(0, 0.17, 0.37);
    drawBuilding(0.71, 0.84, 1);
    drawRoad();
    drawSun(1.00, 0.63, 0.18);
    drawClouds(0.5, 0.5, 0.5, 0.4);
    drawCar1(1); //1 indicates early morning
}
void drawMorning()
{
    drawGrass(0.204, 0.51, 0.204);
    drawSky(0.13, 0.36, 0.84);
    drawSun(0.9, 0.9, 0.0);
    drawClouds(0.5, 0.5, 0.5, 0.4);
    drawBuilding(0.71, 0.84, 1);
    drawRoad();
    drawCar1(0);
}

void drawEvening()
{
    drawGrass(0.10, 0.27, 0.11);
    drawSky(1.00, 0.63, 0.18);
    drawSun(1.00, 0.88, 0.74);
    drawClouds(0.5, 0.5, 0.5, 0.4);
    drawBuilding(0.71, 0.84, 1);
    drawRoad();
    drawCar1(0);
}

void drawNight()
{
    drawGrass(0.01, 0.16, 0.00);
    drawSky(0.0, 0.0, 0.0);
    drawSun(0.79, 0.79, 0.79);
    drawClouds(0.5, 0.5, 0.5, 0.4);
    drawBuilding(1, 0.94, 0.28);
    drawRoad();
    drawCar1(1);
}
void drawScene()
{
    if(posOfSUN<=600)
    {
        mode = 0;
        drawEarlyMorning();
    }
    if(posOfSUN>600 && posOfSUN<=1200)
    {
        mode=0;
        drawMorning();
    }
    if(posOfSUN>1200 && posOfSUN<=1800)
    {
            drawEvening();
            mode=1;
            
    }
    if(posOfSUN>1800 && posOfSUN<2400)
    {
            drawNight();
            mode=1;
    }
}
void reset() {
    posOfSUN = 0;
    sunX = sun_x_default;
    sunY = sun_y_default;
    cloudOneSpeed = cloud_1_defSpeed;
    cloudTwoSpeed = cloud_2_defSpeed;
    cloudThreeSpeed = cloud_3_defSpeed;
}
void displayInstructions()
{
    char string[] = {"Press 'P' to pause"};
    char string2[] = {"Press 'A' or 'D' to increase or decrease the speed of the car"};
    glRasterPos2f(0.32, -0.0);
    glColor3f(1.0,1.0,1.0);
    for(int i=0;i<(int)strlen(string);i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
    glRasterPos2f(0.2, -0.02);
    for(int i=0;i<(int)strlen(string2);i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string2[i]);
    
}
void display()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-0.05, 0.85, -0.05, 0.40);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glClear(GL_COLOR_BUFFER_BIT);
    if(pause==1)
        lockPosition();
    else 
    {
        posOfSUN+=0.25;
        if(cloudOneSpeed <= 2.0)
            cloudOneSpeed += 0.000035;
        else
            cloudOneSpeed = cloud_1_defSpeed;
        if(cloudTwoSpeed <= 2.0)
            cloudTwoSpeed += 0.00015;
        else
            cloudTwoSpeed = cloud_2_defSpeed;
        if(cloudThreeSpeed <= 2.0)
            cloudThreeSpeed += 0.000005;
        else
            cloudThreeSpeed = cloud_3_defSpeed;
        if(posOfSUN==600)
            posOfSUN=601.0;
        if(posOfSUN==1200)
            posOfSUN=1201.0;
        if(posOfSUN==1800)
            posOfSUN=1801.0;
        if(posOfSUN==2400)
            reset();
        drawScene();
        if(posOfSUN<=1200)
            sunY += 0.000025;
        if(posOfSUN>1200 && posOfSUN<2400)
            sunY -= 0.000025;
        if(posOfSUN>=0 && posOfSUN<=2400) {
            sunX += 0.0001;
            carPos += carSpeed; 
        }
        if(carPos>=1.1)
        {
            carPos = car_start_pos;
        }

    }
    if(pause==1) 
    {
        drawScene();
    }
    drawScene();
    displayInstructions();
    glutPostRedisplay();
    glFlush();
}
void Pause() {
    if(pause==1) {
        pause=0;
    }
    else {
        pause=1;
        lock=0;
    }
}
void keyStrokes(unsigned char key, int x, int y) 
{
   if(key=='D' || key=='d') {
        carSpeed += 0.0002;
        if(carSpeed>=0.01)
            carSpeed=0.01;
    }
    if(key=='A' || key=='a') {
        carSpeed -= 0.0002;
        if(carSpeed<=-0.0002)
            carSpeed=-0.0002;
    }
    if(key=='P' || key=='p') {
        Pause();
    }
}
int main(int argC,char** argV)
{
    glutInit(&argC, argV);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1200, 800);
    glutInitWindowPosition (100, 100);
    glutCreateWindow("Town Life Simulation");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyStrokes);
    glutMainLoop();
    return 0;
}