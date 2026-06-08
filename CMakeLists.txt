cmake_minimum_required(VERSION 3.8)
project(px4controller)

# 컴파일 옵션
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# 1. 패키지 의존성 찾기
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(px4_msgs REQUIRED)

# 2. 헤더 경로 설정
include_directories(include)

# 3. 실행 파일 정의
add_executable(px4_controller src/px4_controller.cpp src/px4_proxy.cpp)

# 4. 헤더 디렉토리 설정 (include/px4controller 폴더를 포함)
target_include_directories(px4_controller PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

# 5. 종속성 연결 (px4_msgs 포함)
ament_target_dependencies(px4_controller 
  rclcpp 
  px4_msgs 
  sensor_msgs
)

# 6. 설치 규칙
install(TARGETS
  px4_controller
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
  include/
  DESTINATION include
)

install(DIRECTORY
  launch/
  DESTINATION share/${PROJECT_NAME}/launch
)

# 7. 패키지 내보내기
ament_export_dependencies(
  rclcpp
  px4_msgs
  sensor_msgs
)

ament_package()