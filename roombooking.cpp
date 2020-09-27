#include "database.h"
#include "mainwindow.h"
#define service_max 10

// Defining room booking screen //

void MainWindow::roombooking(){
    QScrollArea* scroller = new QScrollArea(this);
    setCentralWidget(scroller);
    QWidget *window = new QWidget(this);
    window->setStyleSheet("*{background:white;}");
        QVBoxLayout *main_layout =new QVBoxLayout();  //Defining Vertical Box Layout

            //Displays User Details Text At Center
            QLabel *user_label = new QLabel(window);
            user_label->setText("User Details");
            user_label->setAlignment(Qt::AlignHCenter);
            QFont font("Helvetica",30,QFont::Bold);
            user_label->setFont(font);
            user_label->show();

            //Diaplays Name Form
            QWidget *userForm = new QWidget(window);
            QGridLayout *user_formLayout = new QGridLayout(); // Defines grid layout for name
            user_formLayout->setColumnMinimumWidth(1,300);

            // Form Fields Start
            //Hint Text
            QLabel *nameHint = new QLabel("Name");
            nameHint->setStyleSheet("*{font-weight:bold;font-size:15px;padding:10px;}");

            QLabel *emailHint = new QLabel("Email");
            emailHint->setStyleSheet("*{font-weight:bold;font-size:15px;padding:10px;}");

            QLabel *phoneHint = new QLabel("Phone No.");
            phoneHint->setStyleSheet("*{font-weight:bold;font-size:15px;padding:10px;}");

            QLabel *addressHint = new QLabel("Address");
            addressHint->setStyleSheet("*{font-weight:bold;font-size:15px;padding:10px;}");

            QLabel *nationalityHint = new QLabel("Nationality");
            nationalityHint->setStyleSheet("*{font-weight:bold;font-size:15px;padding:10px;}");

            // Input Forms
            this->customer_name = new QLineEdit();    //this refers to the MainWindow class
            this->customer_email = new QLineEdit();
            this->customer_phone = new QLineEdit();
            customer_phone->setValidator(new QIntValidator(0,1000000000,this));
            this->customer_address = new QLineEdit();
            this->customer_nationality = new QLineEdit();

            //font style
            customer_name->setFixedHeight(40);
            customer_name->setClearButtonEnabled(true);

            customer_email->setFixedHeight(40);
            customer_email->setPlaceholderText("Active Email");
            customer_email->setClearButtonEnabled(true);

            customer_phone->setFixedHeight(40);
            customer_phone->setClearButtonEnabled(true);

            customer_address->setFixedHeight(40);
            customer_address->setClearButtonEnabled(true);
            customer_address->setPlaceholderText("Current Address");

            customer_nationality->setFixedHeight(40);
            customer_nationality->setClearButtonEnabled(true);

            //Adding widgets in the userForm layout
            user_formLayout->addWidget(nameHint,0,0);
            user_formLayout->addWidget(customer_name,0,1);

            user_formLayout->addWidget(emailHint,1,0);
            user_formLayout->addWidget(customer_email,1,1);

            user_formLayout->addWidget(phoneHint,2,0);
            user_formLayout->addWidget(customer_phone,2,1);

            user_formLayout->addWidget(addressHint,3,0);
            user_formLayout->addWidget(customer_address,3,1);

            user_formLayout->addWidget(nationalityHint,4,0);
            user_formLayout->addWidget(customer_nationality,4,1);

            user_formLayout->setColumnStretch(4,1);
            userForm->setLayout(user_formLayout); //userForm layout set

            //Diaplays Room details Form
            QWidget *room_form = new QWidget(window);
            QGridLayout *room_formLayout = new QGridLayout(); // Defines grid layout for name
            room_formLayout->setColumnMinimumWidth(1,300);

            //Room select
            QLabel *room_select = new QLabel("ROOM:");
            room_select->setStyleSheet("*{font-weight:bold;font-size:20px;padding:12px;}");

            //Room select check box from mainwindow
            room1_checkbox = new QCheckBox("Room 1",this);
            room2_checkbox = new QCheckBox("Room 2",this);
            room3_checkbox = new QCheckBox("Room 3",this);
            room4_checkbox = new QCheckBox("Room 4",this);
            room5_checkbox = new QCheckBox("Room 5",this);
            room6_checkbox = new QCheckBox("Room 6",this);
            room7_checkbox = new QCheckBox("Room 7",this);
            room8_checkbox = new QCheckBox("Room 8",this);

            QSqlQuery roomavailability_qry(db);
            roomavailability_qry.exec("select room_status from room");
            roomavailability_qry.next();
            if(roomavailability_qry.value(0).toString() == "OCCUPIED"){ room1_checkbox->setEnabled(false);}
            roomavailability_qry.next();
            if(roomavailability_qry.value(0).toString() == "OCCUPIED"){ room2_checkbox->setEnabled(false);}
            roomavailability_qry.next();
            if(roomavailability_qry.value(0).toString() == "OCCUPIED"){ room3_checkbox->setEnabled(false);}
            roomavailability_qry.next();
            if(roomavailability_qry.value(0).toString() == "OCCUPIED"){ room4_checkbox->setEnabled(false);}
            roomavailability_qry.next();
            if(roomavailability_qry.value(0).toString() == "OCCUPIED"){ room5_checkbox->setEnabled(false);}
            roomavailability_qry.next();
            if(roomavailability_qry.value(0).toString() == "OCCUPIED"){ room6_checkbox->setEnabled(false);}
            roomavailability_qry.next();
            if(roomavailability_qry.value(0).toString() == "OCCUPIED"){ room7_checkbox->setEnabled(false);}
            roomavailability_qry.next();
            if(roomavailability_qry.value(0).toString() == "OCCUPIED"){ room8_checkbox->setEnabled(false);}


            //Additional service select
            QLabel *service_select = new QLabel("SERVICES:");
            service_select->setStyleSheet("*{font-weight:bold;font-size:20px;padding:12px;}");

            //Room select check box
            dinner_checkbox = new QCheckBox("DINNER",this);
            breakfast_checkbox = new QCheckBox("BREAKFAST",this);
            lunch_checkbox = new QCheckBox("LUNCH",this);
            transportation_checkbox = new QCheckBox("TRANSPORTATION",this);
            sim_checkbox = new QCheckBox("SIM",this);
            guide_checkbox = new QCheckBox("GUIDE",this);

            //for days staying
            QLabel *days_Hint = new QLabel("Days Staying");
            days_Hint->setStyleSheet("*{font-weight:bold;font-size:18px;padding:10px;}");
            this->days_staying = new QLineEdit();
            days_staying->setFixedHeight(40);
            days_staying->setValidator(new QIntValidator(0,1000000000,this));
            QPushButton *daysstaying_addButton = new QPushButton("ADD");
            daysstaying_addButton->setStyleSheet("*{background:blue;height:30px;}");
            QPushButton *daysstaying_clearButton = new QPushButton("CLEAR");
            daysstaying_clearButton->setStyleSheet("*{background:blue;height:30px;}");

            //for package selection
            QLabel *packageHint = new QLabel("Package Id");
            packageHint->setStyleSheet("*{font-weight:bold;font-size:18px;padding:10px;}");
            this->package_id = new QLineEdit();
            package_id->setFixedHeight(40);
            QPushButton *package_addButton = new QPushButton("ADD");
            package_addButton->setStyleSheet("*{background:blue;height:30px;}");
            QPushButton *package_clearButton = new QPushButton("CLEAR");
            package_clearButton->setStyleSheet("*{background:blue;height:30px;}");

            //for price
            display_price = new QLineEdit();
            display_price->setReadOnly(true);
            display_price->setFixedSize(200,40);
            QLabel* price_label = new QLabel;
            price_label->setText("Total price:");
            QLabel* paying_price = new QLabel;
            paying_price->setText("Paying Price:");
            price_paid = new QLineEdit();
            price_paid->setValidator(new QIntValidator(0,1000000000,this));
            price_paid->setFixedSize(200,40);

            //Adding widgets in the room_FormLayout
            room_formLayout->addWidget(room_select,0,0);
            room_formLayout->addWidget(room1_checkbox,1,0);
            room_formLayout->addWidget(room2_checkbox,1,1);
            room_formLayout->addWidget(room3_checkbox,1,2);
            room_formLayout->addWidget(room4_checkbox,1,3);
            room_formLayout->addWidget(room5_checkbox,2,0);
            room_formLayout->addWidget(room6_checkbox,2,1);
            room_formLayout->addWidget(room7_checkbox,2,2);
            room_formLayout->addWidget(room8_checkbox,2,3);

            room_formLayout->addWidget(service_select,3,0);
            room_formLayout->addWidget(dinner_checkbox,4,0);
            room_formLayout->addWidget(breakfast_checkbox,4,1);
            room_formLayout->addWidget(lunch_checkbox,4,2);
            room_formLayout->addWidget(transportation_checkbox,5,0);
            room_formLayout->addWidget(sim_checkbox,5,1);
            room_formLayout->addWidget(guide_checkbox,5,2);
            room_formLayout->addWidget(days_Hint,6,0);
            room_formLayout->addWidget(days_staying,6,1);
            room_formLayout->addWidget(daysstaying_addButton,6,2);
            room_formLayout->addWidget(daysstaying_clearButton,6,3);
            room_formLayout->addWidget(packageHint,7,0);
            room_formLayout->addWidget(package_id,7,1);
            room_formLayout->addWidget(package_addButton,7,2);
            room_formLayout->addWidget(package_clearButton,7,3);

            room_formLayout->addWidget(price_label,8,0);
            room_formLayout->addWidget(display_price,8,1);
            room_formLayout->addWidget(paying_price,9,0);
            room_formLayout->addWidget(price_paid,9,1);

            //Adding layout to room_form
            room_formLayout->setColumnStretch(9,3);
            room_form->setLayout(room_formLayout); //room_form layout set


            //Layout for Buttons
            QWidget *Button_widget = new QWidget(window);
            QGridLayout *buttonLayout = new QGridLayout(); //Layout for back and book now button

            //Book now Button
            QPushButton *book_nowButton = new QPushButton("Book Now");
            book_nowButton->setStyleSheet("*{background:red;height:30px;}");

            // GO Back Button
            QPushButton *backButton = new QPushButton("Back");
            backButton->setStyleSheet("*{background:red;height:30px;}");
            backButton->adjustSize();
            connect(backButton,SIGNAL(clicked(bool)),this,SLOT(Roommain()));

            //adding button widgets to buttonlayout
            buttonLayout->addWidget(backButton,0,0,Qt::AlignLeft);
            buttonLayout->addWidget(book_nowButton,0,3,Qt::AlignRight);
            buttonLayout->setColumnStretch(2,2);
            Button_widget->setLayout(buttonLayout); //Adding Layout to Button_widget

            //Adding widgets to main_layout
            main_layout->addWidget(user_label);
            main_layout->addWidget(userForm);
            main_layout->addWidget(room_form);
            main_layout->addWidget(Button_widget);
            window->setLayout(main_layout);  //main_layout set to main window
            window->adjustSize();

            scroller->setWidget(window);
            scroller->setVisible(true);
            scroller->size();

            connect(book_nowButton,SIGNAL(clicked(bool)),this,SLOT(bookButton_clicked()));
            connect(book_nowButton,SIGNAL(clicked(bool)),this,SLOT(Roommain()));

            connect(room1_checkbox,SIGNAL(clicked(bool)),this,SLOT(totalprice_display1()));
            connect(room2_checkbox,SIGNAL(clicked(bool)),this,SLOT(totalprice_display2()));
            connect(room3_checkbox,SIGNAL(clicked(bool)),this,SLOT(totalprice_display3()));
            connect(room4_checkbox,SIGNAL(clicked(bool)),this,SLOT(totalprice_display4()));
            connect(room5_checkbox,SIGNAL(clicked(bool)),this,SLOT(totalprice_display5()));
            connect(room6_checkbox,SIGNAL(clicked(bool)),this,SLOT(totalprice_display6()));
            connect(room7_checkbox,SIGNAL(clicked(bool)),this,SLOT(totalprice_display7()));
            connect(room8_checkbox,SIGNAL(clicked(bool)),this,SLOT(totalprice_display8()));
            connect(breakfast_checkbox,SIGNAL(clicked(bool)),this,SLOT(totalprice_display9()));
            connect(dinner_checkbox,SIGNAL(clicked(bool)),this,SLOT(totalprice_display10()));
            connect(lunch_checkbox,SIGNAL(clicked(bool)),this,SLOT(totalprice_display11()));
            connect(transportation_checkbox,SIGNAL(clicked(bool)),this,SLOT(totalprice_display12()));
            connect(sim_checkbox,SIGNAL(clicked(bool)),this,SLOT(totalprice_display13()));
            connect(guide_checkbox,SIGNAL(clicked(bool)),this,SLOT(totalprice_display14()));

            connect(daysstaying_addButton,SIGNAL(clicked(bool)),this,SLOT(daysstayed_priceadder()));
            connect(daysstaying_clearButton,SIGNAL(clicked(bool)),this,SLOT(daysstayed_priceclearer()));
            connect(package_addButton,SIGNAL(clicked(bool)),this,SLOT(packageprice_adder()));
            connect(package_clearButton,SIGNAL(clicked(bool)),this,SLOT(packageprice_clearer()));       
}
