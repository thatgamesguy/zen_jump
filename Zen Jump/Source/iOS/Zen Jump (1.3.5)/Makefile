XCPROJECT=-project PTPlayer.xcodeproj
XCWORKSPACE=-workspace PTPlayer.xcodeproj/project.xcworkspace
ARCHIVEPATH=-archivePath bin/PZPlayer.xcarchive
EXPORTPATH=-exportPath bin/PZPlayer.ipa
PROVISION=
SIGNINGID=

all:
	mkdir -p bin
	xcodebuild $(XCPROJECT) clean build
	xcodebuild $(XCWORKSPACE) -scheme PZPlayer archive $(ARCHIVEPATH)
	xcodebuild -exportArchive -exportFormat ipa \
		$(ARCHIVEPATH) $(EXPORTPATH) $(PROVISION) $(SIGNINGID)

clean:
	xcodebuild $(XCPROJECT) -alltargets clean
	rm -rf bin
