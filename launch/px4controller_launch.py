from launch import LaunchDescription
from launch.actions import ExecuteProcess
from launch_ros.actions import Node

def generate_launch_description():
    px4_dir = "/root/PX4-Autopilot"   # 실제 PX4 경로로 수정
    
    return LaunchDescription([
        ExecuteProcess(cmd=["MicroXRCEAgent","udp4","-p","8888"],output="screen"),
#        ExecuteProcess(
#            cmd=["make", "px4_sitl", "sihsim_quadx"],
#            cwd=px4_dir,
#            output="screen",
#            additional_env={
#                "PX4_HOME_LAT": "0.0",
#                "PX4_HOME_LON": "0.0",
#                "PX4_HOME_ALT": "0.0",
             #   "PX4_SYS_AUTOSTART": "4001",
#            }
#        ),
        
        
        Node(
            package="px4controller",
            executable="px4_controller",
            name="px4_controller",
            output="screen"
        )
    ])
