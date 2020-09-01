# python script to create cpp files
import os

def createFolder(dayNo, pathToFolder, pathTolistOfPrograms, startIndex):
	pathToFolder = pathToFolder+'\Day '+dayNo
	os.mkdir(pathToFolder)
	createFiles(pathToFolder,pathTolistOfPrograms,startIndex)
	return

def createFiles(pathToFolder,pathTolistOfPrograms,startIndex):
	with open(pathTolistOfPrograms,'r') as file:
		for count,fileName in enumerate(file.readlines()):
			os.chdir(pathToFolder)
			fileName = str(count+int(startIndex))+'. '+fileName.strip()+'.cpp'
			file = open(fileName,'w')
			file.close()
			print("created File: ",fileName)

def main():
	dayNo = input('Enter day Number: ')
	pathToFolder = input('Enter Path To Folder: ')
	pathTolistOfPrograms= input('Enter Path To List: ')
	startIndex= input('start Index: ')
	createFolder(dayNo, pathToFolder, pathTolistOfPrograms, startIndex)

main()