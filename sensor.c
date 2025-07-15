// smart_traffic/sensor.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <time.h>

int main() {
    int s;
    struct sockaddr_can addr;
    struct ifreq ifr;
    struct can_frame frame;

    s = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    strcpy(ifr.ifr_name, "vcan0");
    ioctl(s, SIOCGIFINDEX, &ifr);

    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    bind(s, (struct sockaddr *)&addr, sizeof(addr));

    srand(time(0));
    while (1) {
        frame.can_id = 0x102;
        frame.can_dlc = 1;
        frame.data[0] = rand() % 2;  // 0 or 1: car absent/present

        write(s, &frame, sizeof(frame));
        printf("Sensor: Car presence sent: %d\n", frame.data[0]);
        sleep(2);
    }
    return 0;
}