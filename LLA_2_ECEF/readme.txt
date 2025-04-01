#Author
    Sameer Mutlak, smutlak@gmail.com, 720-813-5358

# PROJECT: LLA_2_ECEF
    A console C++ application which is created as a code challenge to be submitted to SciTec, Inc. www.scitec.com.

## Description
    When running the application, the following sub-processes will happen:

    1- Read a csv file called "SciTec_code_problem_data.csv" which contains LLA (latitude, longitude, altitude) data plus time epoch time,
        The file should be in the current working directory of the application.
        the colunms in the csv should be 1-epochTime, 2- latitude, 3- longitude, 4-altitude in order, 
        and the separator should be a comma and without a header row. The data should be ordered ascending by the epoch time.

    2- Convert the LLA data to ECEF (Earth-centered, Earth-fixed coordinate system) and save it to a new csv file called "result.csv"
            $Note: a copy of the data will remain in the application memory because it will be used later.

    3- The application will then calculate and print the ECEF coordinates for the following 2 epoch times 
        1532334000 and 1532335268 then print their ECEF coordinate. Because these times do not exist in the source CSV file, their coordinates will 
        be calculated using "Linear interpolation", https://en.wikipedia.org/wiki/Linear_interpolation
                
    4- The application will keep asking the user for epoch times, calculating ECEF coordinates, and print to the screen 
        until the user provides invalid input (non-numeric), which will cause the application to exit."
        $Note: Successfully calculated points will be appended to result.csv.
    

#Useful hint
    I have included a python file to show the trajectory visually "visualize.py", you can run it and see result, 
    this python script will read result.csv and show the 3D graph 
        $Note: when adding epoch time, the script should be re-run to show the new point(s)

### Dependencies
        The only Dependency that shoud be installed is the libmpfr-dev ""Multiple Precision Floating-Point with Correct Rounding."
        it should be installled using:
            sudo apt-get install libmpfr-dev

        $lld
            sameer@sameer-VirtualBox:~/cPlusPlus/LLA_2_ECEF$ ldd ./lla_2_ecef_debug 
            linux-vdso.so.1 (0x00007fffe5ff9000)
            libmpfr.so.6 => /lib/x86_64-linux-gnu/libmpfr.so.6 (0x000072cef0326000)
            libstdc++.so.6 => /lib/x86_64-linux-gnu/libstdc++.so.6 (0x000072cef0000000)
            libgcc_s.so.1 => /lib/x86_64-linux-gnu/libgcc_s.so.1 (0x000072cef02f8000)
            libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x000072ceefc00000)
            libgmp.so.10 => /lib/x86_64-linux-gnu/libgmp.so.10 (0x000072ceeff7c000)
            /lib64/ld-linux-x86-64.so.2 (0x000072cef0404000)
            libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x000072ceefe93000)
        $readelf
            sameer@sameer-VirtualBox:~/cPlusPlus/LLA_2_ECEF$ readelf -d ./lla_2_ecef_debug 
            Dynamic section at offset 0xeb80 contains 30 entries:
            Tag        Type                         Name/Value
            0x0000000000000001 (NEEDED)             Shared library: [libmpfr.so.6]
            0x0000000000000001 (NEEDED)             Shared library: [libstdc++.so.6]
            0x0000000000000001 (NEEDED)             Shared library: [libgcc_s.so.1]
            0x0000000000000001 (NEEDED)             Shared library: [libc.so.6]

### Building
    The code can be compiled with the provided makefile using the standard `make`
    command.
    make lla_2_ecef_debug
    make lla_2_ecef_release

### My_Environment
    $
        sameer@sameer-VirtualBox:~/cPlusPlus/LLA_2_ECEF$ cat /etc/os-release  # Most distributions
        PRETTY_NAME="Ubuntu 24.04.1 LTS"
        NAME="Ubuntu"
        VERSION_ID="24.04"
        VERSION="24.04.1 LTS (Noble Numbat)"
        VERSION_CODENAME=noble
        ID=ubuntu
        ID_LIKE=debian
        HOME_URL="https://www.ubuntu.com/"
        SUPPORT_URL="https://help.ubuntu.com/"
        BUG_REPORT_URL="https://bugs.launchpad.net/ubuntu/"
        PRIVACY_POLICY_URL="https://www.ubuntu.com/legal/terms-and-policies/privacy-policy"
        UBUNTU_CODENAME=noble
        LOGO=ubuntu-logo
    $
        sameer@sameer-VirtualBox:~/cPlusPlus/LLA_2_ECEF$ g++ --version
        g++ (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0
        Copyright (C) 2023 Free Software Foundation, Inc.
        This is free software; see the source for copying conditions.  There is NO
        warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
    $
        sameer@sameer-VirtualBox:~/cPlusPlus/LLA_2_ECEF$ strings /usr/lib/x86_64-linux-gnu/libstdc++.so.6 | grep GLIBCXX  # Adjust path if needed
        GLIBCXX_3.4
        GLIBCXX_3.4.1
        GLIBCXX_3.4.2
        GLIBCXX_3.4.3
        GLIBCXX_3.4.4
        GLIBCXX_3.4.5
        GLIBCXX_3.4.6
        GLIBCXX_3.4.7
        GLIBCXX_3.4.8
        GLIBCXX_3.4.9
        GLIBCXX_3.4.10
        GLIBCXX_3.4.11
        GLIBCXX_3.4.12
        GLIBCXX_3.4.13
        GLIBCXX_3.4.14
        GLIBCXX_3.4.15
        GLIBCXX_3.4.16
        GLIBCXX_3.4.17
        GLIBCXX_3.4.18
        GLIBCXX_3.4.19
        GLIBCXX_3.4.20
        GLIBCXX_3.4.21
        GLIBCXX_3.4.22
        GLIBCXX_3.4.23
        GLIBCXX_3.4.24
        GLIBCXX_3.4.25
        GLIBCXX_3.4.26
        GLIBCXX_3.4.27
        GLIBCXX_3.4.28
        GLIBCXX_3.4.29
        GLIBCXX_3.4.30
        GLIBCXX_3.4.31
        GLIBCXX_3.4.32
        GLIBCXX_3.4.33
        GLIBCXX_TUNABLES
        GLIBCXX_DEBUG_MESSAGE_LENGTH






sudo apt-get install libmpfr-dev


constexpr double wgs84_a = 6378137.0;
constexpr double wgs84_b = 6356752.31424518;
constexpr double wgs84_a2 = wgs84_a * wgs84_a;
constexpr double wgs84_b2 = wgs84_b * wgs84_b;
constexpr double wgs84_e2 = (1-(wgs84_b2/wgs84_a2));
// constexpr long double wgs84_e = sqrt(wgs84_e2);

