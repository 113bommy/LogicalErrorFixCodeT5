import subprocess

def run_test_cases(cpp_file_path, test_cases_file_path):
    # C++ 파일 컴파일
    compile_result = subprocess.run(['g++', '-o', 'test_program', cpp_file_path])
    if compile_result.returncode != 0:
        print("Compilation failed.")
        return

    # 테스트 케이스 파일 읽기
    with open(test_cases_file_path, 'r') as file:
        test_cases = file.read().split('\n\n')  # 각 테스트 케이스 분리

    for test_case in test_cases:
        if not test_case.strip():
            continue
        input_part, output_part = test_case.split('\noutput: ')
        input_data = input_part.split('input: ')[1]
        expected_output = output_part.strip()

        # 실행 파일에 입력값 제공 및 출력 캡처
        process = subprocess.run(['./test_program'], input=input_data, text=True, capture_output=True)
        actual_output = process.stdout.strip()

        # 예상 출력과 실제 출력 비교
        if actual_output == expected_output:
            print("Test passed.")
        else:
            print(f"Test failed. Expected: '{expected_output}', got: '{actual_output}'")

# 예제 사용
cpp_file_path = 'your_cpp_file.cpp'  # C++ 파일 경로
test_cases_file_path = 'test_cases.txt'  # 테스트 케이스 파일 경로
run_test_cases(cpp_file_path, test_cases_file_path)
