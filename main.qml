import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
Window {
    id: listgoods_window
    width: 800
    height: 600
    visible: true
    title: qsTr("Ban Vien")

    Dialog{
        title: "Detail"
        id: dialog
        topMargin: parent.height/3
        leftMargin: parent.width/4
        width: parent.width/3
        height: parent.height/3
        Button{
            id: btn_detail_select
            width: dialog.width/3
            height: dialog.height/6
            y: dialog.height/1.4
            onClicked: {
               DB.hello()
            }

        }
    }

    Rectangle{
        visible: true
        id: waittingscreen
        width: parent.width
        height: parent.height
        color: "lightblue"
        Image {
            id: wattingscreen
            width: parent.width
            height: parent.height
            source: "file:///C:/Users/A C E R/Desktop/vendingmachine/VendingMachine_QtCreater/img/Waitting_Image.png"
        }
        MouseArea{
            anchors.fill: parent
            onClicked: {
                listgoods.visible =  true
                waittingscreen.visible = false
            }
        }
    }


    Rectangle{
        visible: false
        id: listgoods
        width: parent.width
        height: parent.height
        Image {

            id: listgoods_image
            width: parent.width*2/3
            height: parent.height
            source: "file:///C:/Users/A C E R/Desktop/vendingmachine/VendingMachine_QtCreater/img/MicrosoftTeams-image.png"
        }
        Grid{
            columns: 10
            rows: 6
            x:listgoods_image.width/18
            y:listgoods_image.height/15
            columnSpacing:listgoods_image.width/50
            rowSpacing: listgoods_image.height/34
            Button{
                id: btn_1_1
                width: listgoods_image.width/14
                height: listgoods_image.height/10
                icon.source: "https://github.com/QLoc200501/Vending-Machine/blob/main/img/coca.png?raw=true "
                icon.color: "transparent"
                icon.height: listgoods_image.width/14
                icon.width: listgoods_image.height/10
                flat: true
                onClicked: dialog.open()



            }
            Button{
                id: btn_1_2
                width: listgoods_image.width/14
                height: listgoods_image.height/10
                icon.source: "https://th.bing.com/th/id/R.ef26c0052695cc9e4630970755b64bf9?rik=diLAL9jBrqK%2b1A&pid=ImgRaw&r=0"
                icon.color: "transparent"
                icon.height: listgoods_image.width/14
                icon.width: listgoods_image.height/10
                flat: true
                onClicked: dialog.open()
            }
            Button{
                id: btn_1_3
                width: listgoods_image.width/14
                height: listgoods_image.height/10
            }
            Button{
                id: btn_1_4
                width: listgoods_image.width/14
                height: listgoods_image.height/10
            }
            Button{
                id: btn_1_5
                width: listgoods_image.width/14
                height: listgoods_image.height/10
            }
            Button{
                id: btn_1_6
                width: listgoods_image.width/14
                height: listgoods_image.height/10
            }
            Button{
                id: btn_1_7
                width: listgoods_image.width/14
                height: listgoods_image.height/10
            }
            Button{
                id: btn_1_8
                width: listgoods_image.width/14
                height: listgoods_image.height/10
            }
            Button{
                id: btn_1_9
                width: listgoods_image.width/14
                height: listgoods_image.height/10
            }
            Button{
                id: btn_1_10
                width: listgoods_image.width/14
                height: listgoods_image.height/10
            }
            Button{
                id: btn_2_1
                width: listgoods_image.width/14
                height: listgoods_image.height/10
            }
            Button{
                id: btn_2_2
                width: listgoods_image.width/14
                height: listgoods_image.height/10
            }
            Button{
                id: btn_2_3
                width: listgoods_image.width/14
                height: listgoods_image.height/10
            }
            Button{
                id: btn_2_4
                width: listgoods_image.width/14
                height: listgoods_image.height/10
            }
            Button{
                id: btn_2_5
                width: listgoods_image.width/14
                height: listgoods_image.height/10
            }
            Button{
                id: btn_2_6
                width: listgoods_image.width/14
                height: listgoods_image.height/10
            }
            Button{
                id: btn_2_7
                width: listgoods_image.width/14
                height: listgoods_image.height/10
            }
            Button{
                id: btn_2_8
                width: listgoods_image.width/14
                height: listgoods_image.height/10
            }
            Button{
                id: btn_2_9
                width: listgoods_image.width/14
                height: listgoods_image.height/10
            }
            Button{
                id: btn_2_10
                width: listgoods_image.width/14
                height: listgoods_image.height/10
            }
        }
    }
}

