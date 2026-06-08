from launch import LaunchDescription
from launch.actions import ExecuteProcess
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package="px4controller",
            executable="px4_controller",
            name="px4_controller",
            output="screen"
        )
    ])
