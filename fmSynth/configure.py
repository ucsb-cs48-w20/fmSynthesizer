import os
from subprocess import call

if not os.path.exists("../external/FRUT/prefix"):
    os.chdir("../external/FRUT/")
    call(["cmake", "-E", "make_directory", "build"])
    os.chdir("build/")
    call(["cmake", "..", "-DCMAKE_INSTALL_PREFIX=../prefix -DJUCE_ROOT=../../JUCE"])
    
#    subprocess.Popen(["cmake", "..", "-DCMAKE_INSTALL_PREFIX=../prefix -DJUCE_ROOT=../../JUCE"], stdout=subprocess.PIPE)
#    subprocess.Popen(["cmake", "--build", ".", "--target install"], stdout=subprocess.PIPE)
    
#		os.system("cd ../external/FRUT/")
#
#		os.system("cd build/")
#		subprocess.Popen(["cmake", "..", "-DCMAKE_INSTALL_PREFIX=../prefix -DJUCE_ROOT=../../JUCE"], stdout=subprocess.PIPE)
#		subprocess.Popen(["cmake", "--build", ".", "--target install"], stdout=subprocess.PIPE)
