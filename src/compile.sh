
date=`date +%Y-%m-%d_%H-%M`
directory="build_"$date

mkdir $directory
cd $directory
cmake ..
make -j
cp VisualizationFramework ..
cd ..

