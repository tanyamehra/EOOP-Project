##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Prelim
ConfigurationName      :=Debug
WorkspacePath          :=D:/ygrek/Ina
ProjectPath            :=D:/ygrek/Tanya/Prelim
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Unelith
Date                   :=17/01/2019
CodeLitePath           :="D:/Małe programy/CodeLite"
LinkerName             :=D:/CodeBlocks/MinGW/bin/g++.exe
SharedObjectLinkerName :=D:/CodeBlocks/MinGW/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Prelim.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=D:/CodeBlocks/MinGW/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := D:/CodeBlocks/MinGW/bin/ar.exe rcu
CXX      := D:/CodeBlocks/MinGW/bin/g++.exe
CC       := D:/CodeBlocks/MinGW/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := D:/CodeBlocks/MinGW/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=D:\Małe programy\CodeLite
Objects0=$(IntermediateDirectory)/Fanpage.cpp$(ObjectSuffix) $(IntermediateDirectory)/NewsPortal.cpp$(ObjectSuffix) $(IntermediateDirectory)/Website.cpp$(ObjectSuffix) $(IntermediateDirectory)/Admin.cpp$(ObjectSuffix) $(IntermediateDirectory)/CompanyWebsite.cpp$(ObjectSuffix) $(IntermediateDirectory)/Blog.cpp$(ObjectSuffix) $(IntermediateDirectory)/Internet.cpp$(ObjectSuffix) $(IntermediateDirectory)/Post.cpp$(ObjectSuffix) $(IntermediateDirectory)/User.cpp$(ObjectSuffix) $(IntermediateDirectory)/Person.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/Guest.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Fan.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/Fanpage.cpp$(ObjectSuffix): Fanpage.cpp $(IntermediateDirectory)/Fanpage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/ygrek/Tanya/Prelim/Fanpage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Fanpage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Fanpage.cpp$(DependSuffix): Fanpage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Fanpage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Fanpage.cpp$(DependSuffix) -MM Fanpage.cpp

$(IntermediateDirectory)/Fanpage.cpp$(PreprocessSuffix): Fanpage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Fanpage.cpp$(PreprocessSuffix) Fanpage.cpp

$(IntermediateDirectory)/NewsPortal.cpp$(ObjectSuffix): NewsPortal.cpp $(IntermediateDirectory)/NewsPortal.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/ygrek/Tanya/Prelim/NewsPortal.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/NewsPortal.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/NewsPortal.cpp$(DependSuffix): NewsPortal.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/NewsPortal.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/NewsPortal.cpp$(DependSuffix) -MM NewsPortal.cpp

$(IntermediateDirectory)/NewsPortal.cpp$(PreprocessSuffix): NewsPortal.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/NewsPortal.cpp$(PreprocessSuffix) NewsPortal.cpp

$(IntermediateDirectory)/Website.cpp$(ObjectSuffix): Website.cpp $(IntermediateDirectory)/Website.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/ygrek/Tanya/Prelim/Website.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Website.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Website.cpp$(DependSuffix): Website.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Website.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Website.cpp$(DependSuffix) -MM Website.cpp

$(IntermediateDirectory)/Website.cpp$(PreprocessSuffix): Website.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Website.cpp$(PreprocessSuffix) Website.cpp

$(IntermediateDirectory)/Admin.cpp$(ObjectSuffix): Admin.cpp $(IntermediateDirectory)/Admin.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/ygrek/Tanya/Prelim/Admin.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Admin.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Admin.cpp$(DependSuffix): Admin.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Admin.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Admin.cpp$(DependSuffix) -MM Admin.cpp

$(IntermediateDirectory)/Admin.cpp$(PreprocessSuffix): Admin.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Admin.cpp$(PreprocessSuffix) Admin.cpp

$(IntermediateDirectory)/CompanyWebsite.cpp$(ObjectSuffix): CompanyWebsite.cpp $(IntermediateDirectory)/CompanyWebsite.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/ygrek/Tanya/Prelim/CompanyWebsite.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CompanyWebsite.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CompanyWebsite.cpp$(DependSuffix): CompanyWebsite.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CompanyWebsite.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CompanyWebsite.cpp$(DependSuffix) -MM CompanyWebsite.cpp

$(IntermediateDirectory)/CompanyWebsite.cpp$(PreprocessSuffix): CompanyWebsite.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CompanyWebsite.cpp$(PreprocessSuffix) CompanyWebsite.cpp

$(IntermediateDirectory)/Blog.cpp$(ObjectSuffix): Blog.cpp $(IntermediateDirectory)/Blog.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/ygrek/Tanya/Prelim/Blog.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Blog.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Blog.cpp$(DependSuffix): Blog.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Blog.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Blog.cpp$(DependSuffix) -MM Blog.cpp

$(IntermediateDirectory)/Blog.cpp$(PreprocessSuffix): Blog.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Blog.cpp$(PreprocessSuffix) Blog.cpp

$(IntermediateDirectory)/Internet.cpp$(ObjectSuffix): Internet.cpp $(IntermediateDirectory)/Internet.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/ygrek/Tanya/Prelim/Internet.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Internet.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Internet.cpp$(DependSuffix): Internet.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Internet.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Internet.cpp$(DependSuffix) -MM Internet.cpp

$(IntermediateDirectory)/Internet.cpp$(PreprocessSuffix): Internet.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Internet.cpp$(PreprocessSuffix) Internet.cpp

$(IntermediateDirectory)/Post.cpp$(ObjectSuffix): Post.cpp $(IntermediateDirectory)/Post.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/ygrek/Tanya/Prelim/Post.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Post.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Post.cpp$(DependSuffix): Post.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Post.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Post.cpp$(DependSuffix) -MM Post.cpp

$(IntermediateDirectory)/Post.cpp$(PreprocessSuffix): Post.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Post.cpp$(PreprocessSuffix) Post.cpp

$(IntermediateDirectory)/User.cpp$(ObjectSuffix): User.cpp $(IntermediateDirectory)/User.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/ygrek/Tanya/Prelim/User.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/User.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/User.cpp$(DependSuffix): User.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/User.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/User.cpp$(DependSuffix) -MM User.cpp

$(IntermediateDirectory)/User.cpp$(PreprocessSuffix): User.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/User.cpp$(PreprocessSuffix) User.cpp

$(IntermediateDirectory)/Person.cpp$(ObjectSuffix): Person.cpp $(IntermediateDirectory)/Person.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/ygrek/Tanya/Prelim/Person.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Person.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Person.cpp$(DependSuffix): Person.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Person.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Person.cpp$(DependSuffix) -MM Person.cpp

$(IntermediateDirectory)/Person.cpp$(PreprocessSuffix): Person.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Person.cpp$(PreprocessSuffix) Person.cpp

$(IntermediateDirectory)/Guest.cpp$(ObjectSuffix): Guest.cpp $(IntermediateDirectory)/Guest.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/ygrek/Tanya/Prelim/Guest.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Guest.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Guest.cpp$(DependSuffix): Guest.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Guest.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Guest.cpp$(DependSuffix) -MM Guest.cpp

$(IntermediateDirectory)/Guest.cpp$(PreprocessSuffix): Guest.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Guest.cpp$(PreprocessSuffix) Guest.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/ygrek/Tanya/Prelim/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/Fan.cpp$(ObjectSuffix): Fan.cpp $(IntermediateDirectory)/Fan.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/ygrek/Tanya/Prelim/Fan.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Fan.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Fan.cpp$(DependSuffix): Fan.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Fan.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Fan.cpp$(DependSuffix) -MM Fan.cpp

$(IntermediateDirectory)/Fan.cpp$(PreprocessSuffix): Fan.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Fan.cpp$(PreprocessSuffix) Fan.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


