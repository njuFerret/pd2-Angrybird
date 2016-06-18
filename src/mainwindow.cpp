#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Enable the event Filter
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
//    itemList.push_back(new Land(20,2,40,5,QPixmap(":/gd").scaled(800,100),world,scene));

    // Create bird (You can edit here)
//     Bird *birdie = new Bird(0.0f,15.0f,1.05f,&timer,QPixmap(":/bird.png").scaled(46,46),world,scene);

    // Bird *birdie = new Bird(0.0f,10.0f,0.27f,&timer,QPixmap(":/bird.png").scaled(height()/9.0,height()/9.0),world,scene);

     Enemy *enemy = new Enemy(31.0f,15.0f,1.1f,&timer,QPixmap(":/enemy").scaled(50,50),world,scene);
    // Setting the Velocity
//    birdie->setLinearVelocity(b2Vec2(8,7));
//    itemList.push_back(birdie);
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
    itemList.push_back(new Land(12.00f,6.25f,1.00f,4.0f,QPixmap("").scaled(0,0),world,scene));
    itemList.push_back(new Land(40.00f,17.5f,1.00f,25.0f,QPixmap("").scaled(0,0),world,scene));

    button *quit = new button();
    quit->setPos(734,10);
    quit->setPixmap(QPixmap(":/exit"));
    connect(quit,SIGNAL(clicked()),this,SLOT(quitslot()));
    scene->addItem(quit);

    // Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    timer.start(100/6);

    cnt = 0;
}

bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    // Hint: Notice the Number of every event!
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
                /*Bird **/birdie = new Bird(a,b,1.05f,&timer,QPixmap(":/bird.png").scaled(46,46),world,scene);
//              birdie = new yellowb(a,b,1.05f,&timer,QPixmap(":/y").scaled(50,50),world,scene);

                vx = -1.5*(a - 12);
                vy = -1.5*(b - 13.5);
                birdie->setLinearVelocity(b2Vec2(vx,vy));
                itemList.push_back(birdie);
                cnt ++;
                return true;
            }
//            float vxx, vyy;
//            vxx = birdie->getLinearVelocity().x;
//            vyy = birdie->getLinearVelocity().y;
//            std::cout << vxx << " " << vyy << std::endl;
//          if (vxx == 0 && vyy == 0){
//              birdie->g_pixmap.setPixmap(QPixmap(":/r"));
//             deleteBird();
//          }
//          timer2.stop();
//          connect(&timer2 , SIGNAL(timeout()) , this , SLOT(deleteBird()));
//            cnt ++ ;
//            return true;
            //        std::cout << "Press !" << std::endl ;
            break ;
        }
        case 1:{
//            delete birdie;
            float a, b,vx,vy;
            QMouseEvent *E = static_cast<QMouseEvent *>(event);
            a = (E->x())/20.0f;    //   get the coordinate of px
            b = 30 - (E->y())/20.0f;
//          std::cout<< E->x() << " " << E->y() << std::endl;   // for debug   check the px
            if(E->x()< 245 && E->y() < 500){
                delete birdie;
//              /*Bird **/birdie = new Bird(a,b,1.05f,&timer,QPixmap(":/bird.png").scaled(46,46),world,scene);
                birdie = new yellowb(a,b,1.05f,&timer,QPixmap(":/y").scaled(50,50),world,scene);

                vx = -1.5*(a - 12);
                vy = -1.5*(b - 13.5);
                birdie->setLinearVelocity(b2Vec2(vx,vy));
                itemList.push_back(birdie);
                cnt++;
                return true;
            }
            float vxx, vyy;
            vxx = birdie->getLinearVelocity().x;
            vyy = birdie->getLinearVelocity().y;
            std::cout << vxx << " " << vyy << std::endl;
//          if (vxx == 0 && vyy == 0){
//              birdie->g_pixmap.setPixmap(QPixmap(":/r"));
//             deleteBird();
//          }
//            cnt++ ;
//            return true;
            break ;
        }
        case 2:{
//            delete birdie;
            float a, b,vx,vy;
            QMouseEvent *E = static_cast<QMouseEvent *>(event);
            a = (E->x())/20.0f;    //   get the coordinate of px
            b = 30 - (E->y())/20.0f;
//          std::cout<< E->x() << " " << E->y() << std::endl;   // for debug   check the px
            if(E->x()< 245 && E->y() < 500){
                delete birdie;
//              /*Bird **/birdie = new Bird(a,b,1.05f,&timer,QPixmap(":/bird.png").scaled(46,46),world,scene);
                birdie = new whiteb(a,b,1.05f,&timer,QPixmap(":/w").scaled(50,50),world,scene);

                vx = -1.5*(a - 12);
                vy = -1.5*(b - 13.5);
                birdie->setLinearVelocity(b2Vec2(vx,vy));
                itemList.push_back(birdie);
                cnt++;
                return true;
            }
            float vxx, vyy;
            vxx = birdie->getLinearVelocity().x;
            vyy = birdie->getLinearVelocity().y;
            std::cout << vxx << " " << vyy << std::endl;
//          if (vxx == 0 && vyy == 0){
//              birdie->g_pixmap.setPixmap(QPixmap(":/r"));
//             deleteBird();
//          }
//            cnt++ ;
//            return true;
            break ;

        }
        case 3:{
//            delete birdie;
            float a, b,vx,vy;
            QMouseEvent *E = static_cast<QMouseEvent *>(event);
            a = (E->x())/20.0f;    //   get the coordinate of px
            b = 30 - (E->y())/20.0f;
//          std::cout<< E->x() << " " << E->y() << std::endl;   // for debug   check the px
            if(E->x()< 245 && E->y() < 500){
                delete birdie;
//              /*Bird **/birdie = new Bird(a,b,1.05f,&timer,QPixmap(":/bird.png").scaled(46,46),world,scene);
                birdie = new bigb(a,b,1.05f,&timer,QPixmap(":/r").scaled(50,50),world,scene);

                vx = -1.5*(a - 12);
                vy = -1.5*(b - 13.5);
                birdie->setLinearVelocity(b2Vec2(vx,vy));
                itemList.push_back(birdie);
                cnt++;
                return true;
            }
//            float vxx, vyy;
//            vxx = birdie->getLinearVelocity().x;
//            vyy = birdie->getLinearVelocity().y;
//            std::cout << vxx << " " << vyy << std::endl;
//          if (vxx == 0 && vyy == 0){
//              birdie->g_pixmap.setPixmap(QPixmap(":/r"));
//             deleteBird();
//          }
//            cnt++ ;
//            return true;
//            break ;
        }

        }   //switch
        if(cnt != 0){
            float j,q;
//          int k;
            QMouseEvent *press = static_cast<QMouseEvent *>(event);
//          j = (press->x())/20.0f;    //   get the coordinate of px
//          q = 30 - (press->y())/20.0f;
//          std::cout<< press->x() << " " << press->y() << std::endl;   // for debug   check the px
            if(press->x() > 240){
                k = birdie->special();
//                std::cout<< k << std::endl;
            }
            float vxx, vyy;
            vxx = birdie->getLinearVelocity().x;
            vyy = birdie->getLinearVelocity().y;
//          std::cout << vxx << " " << vyy << std::endl;
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
    if(event->type() == QEvent::MouseMove)
    {
        /* TODO : add your code here */
        //std::cout << "Move !" << std::endl ;
    }
    if(event->type() == QEvent::MouseButtonRelease)
    {
        /* TODO : add your code here */
        //std::cout << "Release !" << std::endl ;
    }
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

//void MainWindow::deleteBird()
//{
//    foreach (Bird *i, list) {
//        if(i->getLinearVelocity() == b2Vec2(0.0f,0.0f))
//        {
//            i->removeBird(scene);
//            list.removeOne(i);
//            delete i;
//            cnt++;
//        }
//    }
//}

