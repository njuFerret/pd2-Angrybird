#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qApp->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{

    // Setting the QGraphicsScene
    scene = new QGraphicsScene(0,0,width(),ui->graphicsView->height());
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    ui->graphicsView->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    // Create world
    world = new b2World(b2Vec2(0.0f, -9.8f));
    // Setting Size
//    GameItem::setGlobalSize(QSizeF(40,30),size());
    GameItem::setGlobalSize(QSizeF(40,30),QSizeF(800,600));
    // Create ground (You can edit here)
    itemList.push_back(new Land(20,2.5,40,5,QPixmap(":/ground.png").scaled(800,80),world,scene));

    enemy = new Enemy(31.0f,15.0f,1.1f,&timer,QPixmap(":/enemy").scaled(50,50),world,scene);
    itemList.push_back(enemy);
    itemList.push_back(new Barrier(19.00f,12.0f,0.75f,3.0f,&timer,QPixmap(":/barrier").scaled(15,60),world,scene));
    itemList.push_back(new Barrier(20.00f,12.0f,0.75f,3.0f,&timer,QPixmap(":/barrier").scaled(15,60),world,scene));
    itemList.push_back(new Barrier(25.00f,12.0f,0.75f,3.0f,&timer,QPixmap(":/barrier").scaled(15,60),world,scene));
    itemList.push_back(new Barrier(18.00f,12.0f,0.75f,3.0f,&timer,QPixmap(":/barrier").scaled(15,60),world,scene));
    itemList.push_back(new Barrier(18.00f,16.0f,0.75f,3.0f,&timer,QPixmap(":/barrier").scaled(15,60),world,scene));
    itemList.push_back(new Barrier(18.00f,20.0f,0.75f,3.0f,&timer,QPixmap(":/barrier").scaled(15,60),world,scene));
    itemList.push_back(new Barrier(17.25f,12.0f,0.75f,3.0f,&timer,QPixmap(":/barrier").scaled(15,60),world,scene));
    itemList.push_back(new Barrier(17.25f,16.0f,0.75f,3.0f,&timer,QPixmap(":/barrier").scaled(15,60),world,scene));
    itemList.push_back(new Barrier(17.25f,20.0f,0.75f,3.0f,&timer,QPixmap(":/barrier").scaled(15,60),world,scene));
    itemList.push_back(new Land(12.00f,6.25f,1.00f,4.0f,QPixmap().scaled(0,0),world,scene));
    itemList.push_back(new Land(40.00f,17.5f,1.00f,25.0f,QPixmap().scaled(0,0),world,scene));

    // Button
    button *quit = new button();
    quit->setPos(734,10);
    quit->setPixmap(QPixmap(":/exit"));
    connect(quit,SIGNAL(clicked()),this,SLOT(quitslot()));
    scene->addItem(quit);

    button *restart = new button();
    restart->setPos(650,10);
    restart->setPixmap(QPixmap(":/restart"));
    connect(restart,SIGNAL(clicked()),this,SLOT(restart()));
    scene->addItem(restart); 

    // Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(&timer2,SIGNAL(timeout()),this,SLOT(deleteEnemy()));
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    timer.start(100/6);
    timer2.start(1000);

    cnt = 0;

}

bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress)
    {
        switch(cnt){
         case 0:{
//          timer2.start();
            float a, b,vx,vy;
            QMouseEvent *E = static_cast<QMouseEvent *>(event);
            a = (E->x())/20.0f;    //   get the coordinate of px
            b = 30 - (E->y())/20.0f;
//          std::cout<< E->x() << " " << E->y() << std::endl;   // for debug   check the px
            if(E->x()< 245 && E->y() < 500){
                birdie = new Bird(a,b,1.05f,&timer,QPixmap(":/bird.png").scaled(46,46),world,scene);

                vx = -1.5*(a - 12);
                vy = -1.5*(b - 13.5);
                birdie->setLinearVelocity(b2Vec2(vx,vy));
                itemList.push_back(birdie);
                cnt ++;
                return true;
            }
            break ;
        }
        case 1:{
            float a, b,vx,vy;
            QMouseEvent *E = static_cast<QMouseEvent *>(event);
            a = (E->x())/20.0f;    //   get the coordinate of px
            b = 30 - (E->y())/20.0f;
//          std::cout<< E->x() << " " << E->y() << std::endl;   // for debug   check the px
            if(E->x()< 245 && E->y() < 500){
                delete itemList[itemList.size()-1];
                birdie = new yellowb(a,b,1.05f,&timer,QPixmap(":/y").scaled(50,50),world,scene);

                vx = -1.5*(a - 12);
                vy = -1.5*(b - 13.5);
                birdie->setLinearVelocity(b2Vec2(vx,vy));
                itemList.push_back(birdie);
                cnt++;
                return true;
            }

            break ;
        }
        case 2:{
            float a, b,vx,vy;
            QMouseEvent *E = static_cast<QMouseEvent *>(event);
            a = (E->x())/20.0f;    //   get the coordinate of px
            b = 30 - (E->y())/20.0f;
//          std::cout<< E->x() << " " << E->y() << std::endl;   // for debug   check the px
            if(E->x()< 245 && E->y() < 500){
                delete itemList[itemList.size()-1];
                birdie = new whiteb(a,b,1.05f,&timer,QPixmap(":/w").scaled(50,50),world,scene);

                vx = -1.5*(a - 12);
                vy = -1.5*(b - 13.5);
                birdie->setLinearVelocity(b2Vec2(vx,vy));
                itemList.push_back(birdie);
                cnt++;
                return true;
            }
            break ;
        }
        case 3:{
            float a, b,vx,vy;
            QMouseEvent *E = static_cast<QMouseEvent *>(event);
            a = (E->x())/20.0f;    //   get the coordinate of px
            b = 30 - (E->y())/20.0f;
//          std::cout<< E->x() << " " << E->y() << std::endl;   // for debug   check the px
            if(E->x()< 245 && E->y() < 500){

                for(int i=15;i<itemList.size();i++){
//                    itemList.pop_back();
                    delete itemList[ i ];
                }
                birdie = new bigb(a,b,1.05f,&timer,QPixmap(":/r").scaled(50,50),world,scene);
//                std::cout<<itemList.size()<<std::endl;
                vx = -1.5*(a - 12);
                vy = -1.5*(b - 13.5);
                birdie->setLinearVelocity(b2Vec2(vx,vy));
                itemList.push_back(birdie);
                cnt++;
                return true;
            }
        }
        }   //switch
        if(cnt != 0){
            QMouseEvent *press = static_cast<QMouseEvent *>(event);
                k = birdie->special();
//                std::cout<< k << std::endl;   //debug
       //    }
            float vxx, vyy;
            vxx = birdie->getLinearVelocity().x;
            vyy = birdie->getLinearVelocity().y;
//          std::cout << vxx << " " << vyy << std::endl;
            if(press->x()>240 && press->y()>60){
            switch(k){
                case 1:{
                    birdie->setLinearVelocity(b2Vec2(vxx*2,vyy));
                    break;
                }
                case 2:{
                    float xx,yy;
                    xx = birdie->getPosition().x;
                    yy = birdie->getPosition().y;
                    eggs = new egg(xx,yy-1,0.75f,&timer,QPixmap(":/egg").scaled(30,30),world,scene);
                    itemList.push_back(eggs);
                    birdie->setLinearVelocity(b2Vec2(vxx,vyy+5));
                    return true;
                }
                case 3:{
                    delete birdie;
                    float xx,yy;
                    xx = birdie->getPosition().x;
                    yy = birdie->getPosition().y;
                    birdie = new bigb(xx,yy,1.5f,&timer,QPixmap(":/r").scaled(63,63),world,scene);
                    birdie->setLinearVelocity(b2Vec2(vxx,vyy));

                }
                }
            }
        }
    }
    if(event->type() == QEvent::MouseMove){}
    if(event->type() == QEvent::MouseButtonRelease){}
    return false;
}

void MainWindow::closeEvent(QCloseEvent *)
{
    // Close event
    emit quitGame();
}

void MainWindow::tick()
{
    world->Step(1.0/60.0,6,2);
    scene->update();
}

void MainWindow::QUITSLOT()
{
    // For debug
    std::cout << "Quit Game Signal receive !" << std::endl ;
}

void MainWindow::quitslot()
{
    close();
    delete ui;
}

void MainWindow::restart(){

    qApp->exit( MainWindow::Exit);
//    delete birdie;
//    timer.stop();
//    for(int i=0;i < itemList.size()-cnt;++i){
//        delete itemList[i];
//    }

//   itemList.clear();
//   itemList.push_back(new Land(20,2.5,40,5,QPixmap(":/ground.png").scaled(800,80),world,scene));
//   enemy = new Enemy(31.0f,15.0f,1.1f,&timer,QPixmap(":/enemy").scaled(50,50),world,scene);
//   itemList.push_back(enemy);
//   itemList.push_back(new Barrier(19.00f,12.0f,0.75f,3.0f,&timer,QPixmap(":/barrier").scaled(15,60),world,scene));
//   itemList.push_back(new Barrier(20.00f,12.0f,0.75f,3.0f,&timer,QPixmap(":/barrier").scaled(15,60),world,scene));
//   itemList.push_back(new Barrier(25.00f,12.0f,0.75f,3.0f,&timer,QPixmap(":/barrier").scaled(15,60),world,scene));
//   itemList.push_back(new Barrier(18.00f,12.0f,0.75f,3.0f,&timer,QPixmap(":/barrier").scaled(15,60),world,scene));
//   itemList.push_back(new Barrier(18.00f,16.0f,0.75f,3.0f,&timer,QPixmap(":/barrier").scaled(15,60),world,scene));
//   itemList.push_back(new Barrier(18.00f,20.0f,0.75f,3.0f,&timer,QPixmap(":/barrier").scaled(15,60),world,scene));
//   itemList.push_back(new Barrier(17.25f,12.0f,0.75f,3.0f,&timer,QPixmap(":/barrier").scaled(15,60),world,scene));
//   itemList.push_back(new Barrier(17.25f,16.0f,0.75f,3.0f,&timer,QPixmap(":/barrier").scaled(15,60),world,scene));
//   itemList.push_back(new Barrier(17.25f,20.0f,0.75f,3.0f,&timer,QPixmap(":/barrier").scaled(15,60),world,scene));
//   itemList.push_back(new Land(12.00f,6.25f,1.00f,4.0f,QPixmap().scaled(0,0),world,scene));
//   itemList.push_back(new Land(40.00f,17.5f,1.00f,25.0f,QPixmap().scaled(0,0),world,scene));

//   cnt = 0;
//   timer.start();

}

void MainWindow::deleteEnemy(){
    float vx;
    vx = enemy->getLinearVelocity().x;
    if(vx!=0 ){
        enemy->health--;
        std::cout<<enemy->health;
    }
    if(enemy->health==0){
        delete enemy;
        timer2.stop();
    }
}

int const MainWindow::Exit = 87;
