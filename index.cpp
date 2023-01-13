#include <iostream>
#include <vector>
#include <stdlib.h>

struct hotelRoom {
    int id;
    std::string name;
    float pricePerDay;
    bool isAvailable;
};

class Hotel {
    public:
        void getAllAvailableRooms(std::vector<hotelRoom> arrayRoom){
            for(hotelRoom &room : arrayRoom){
                if(room.isAvailable == true){
                    std::cout << "Room Number: " << room.id << "\n";
                    std::cout << "Room Name: " << room.name << "\n";
                    std::cout << "Room Price: " << room.pricePerDay << "$" << "\n";
                    std::cout << "-----------------" << "\n";
                }
            }
        }

        void rentRoom(int roomNumber, int days, std::vector<hotelRoom> & availableRooms){
            float price;
            for(hotelRoom &room : availableRooms){
                if (room.id == roomNumber){
                     room.isAvailable = false;
                     price = room.pricePerDay;
                }
            }
            std::cout << "You are going to pay " << price * days << "$" << "\n";
        }
};



int main() {
    std::vector<hotelRoom> hotelRoomArray {
            { 1, "Normal", 100.50, true },
            { 2, "Suite", 350.00, true },
    };
    int result;
    Hotel hotel;

    std:: cout << "1 - Rent a Room\n2 - See Available Rooms\n3 - Exit\n";
    std::cin >> result;


    while(result != 3){
        switch (result) {
            case 1:
            {
                int days, roomNumber;
                std::cout << "What's the room number?\n";
                std::cin >> roomNumber;
                std::cout << "How much days you will be stay in this room?\n";
                std::cin >> days;
                hotel.rentRoom(roomNumber, days, hotelRoomArray);
                std:: cout << "1 - Rent a Room\n2 - See Available Rooms\n3 - Exit\n";
                std::cin >> result;
                break;
            }

            case 2:
            {
                hotel.getAllAvailableRooms(hotelRoomArray);
                std:: cout << "1 - Rent a Room\n2 - See Available Rooms\n3 - Exit\n";
                std::cin >> result;
                break;
            }
        }
    }
}
