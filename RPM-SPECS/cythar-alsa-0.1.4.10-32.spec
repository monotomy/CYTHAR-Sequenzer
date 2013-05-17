Name: CYTHAR-Sequenzer
Summary: CYTHAR Sequenzer, a MIDI Sequencer - Jack & Alsa - 0.1.4.10 - 32bit
Version: 0.1.4.10
Release: 1
License: Other
Group: Applications/Multimedia
BuildRoot: %{_tmppath}/%{name}-%{version}-%{release}-root
Source0: CYTHAR-Sequenzer-0.1.4.10.tar.gz
Packager: monotomy@cythar.sequenzer.org
Distribution: Other
Url: http://www.cythar.seqeunzer.org
Vendor: http://www.cythar.seqeunzer.org

%description
A pattern-oriented, polyphonic MIDI step-sequencer, which makes its own path. 16 parallel patterns with six tracks and 16 bars – equating to 256 bars & 96 tracks. The six pattern tracks imitate the strings of a guitar and will be tuned e.g. to - EAdgbe -. With some clicks you can set a guitar chord to the pattern tune – then by enabling a few events or triggers the sequencer will start a solo or plays with the chords. More offset-, mute functions and a tricky song mode will pep-up your set. With CYTHAR you can programme drum sets, melodies, arpeggios and complete songs. If this is not enough try out Rebeca!

%prep


%setup -q

%build


%install
rm 	-rf %{buildroot}
mkdir 	-p  %{buildroot}
cp 	-a * %{buildroot}

#Icon
mkdir 	-p %{buildroot}%{_datadir}/pixmaps
install -m777 usr/share/cythar-projects/* %{buildroot}%{_datadir}/cythar-projects
install -m755 usr/share/pixmaps/cythar_logo.png %{buildroot}%{_datadir}/pixmaps

#Desktopfile for Alsa
mkdir 	-p %{buildroot}%{_datadir}/applications
cat > %{buildroot}%{_datadir}/applications/cythar-alsa_32.desktop << EOF
[Desktop Entry]
  Encoding=UTF-8
  Name=cythar-32-alsa
  GenericName=CYTHAR Sequenzer - Alsa - 32
  Comment=CYTHAR MIDI Sequenzer - Alsa - 0.1.4.10
  Exec=cythar-alsa_32_0.1.4.10
  Terminal=false
#Terminal=false
#TerminalOptions=\s--noclose
  Type=Application
  StartupNotify=true
  Icon=%{_datadir}/pixmaps/cythar_logo.png
  Categories=Applications;Music;Application;X-AudioVideo;X-Audio;X-Sound;X-MIDI;X-Sequencer;
EOF

#Menu for Alsa
desktop-file-install --vendor="" 	\
  --add-category="X-Red-Hat-Base" 	\
  --add-category="Applications" 	\
  --add-category="AudioVideo" 	\
  --dir %{buildroot}%{_datadir}/applications \
%{buildroot}%{_datadir}/applications/cythar-alsa_32.desktop

#Desktopfile for Jack
mkdir 	-p %{buildroot}%{_datadir}/applications
cat > %{buildroot}%{_datadir}/applications/cythar-jack_32.desktop << EOF
[Desktop Entry]
  Encoding=UTF-8
  Name=cythar-32-jack
  GenericName=CYTHAR Sequenzer - Jack - 32
  Comment=CYTHAR MIDI Sequenzer - Jack - 0.1.4.10
  Exec=cythar-jack_32_0.1.4.10
  Terminal=false
#Terminal=true
#TerminalOptions=\s--noclose
  Type=Application
  StartupNotify=true
  Icon=%{_datadir}/pixmaps/cythar_logo.png
  Categories=Applications;Music;Application;X-AudioVideo;X-Audio;X-Sound;X-MIDI;X-Sequencer;
EOF

#Menu for Jack
desktop-file-install --vendor="" 	\
  --add-category="X-Red-Hat-Base" 	\
  --add-category="Applications" 	\
  --add-category="AudioVideo" 	\
  --dir %{buildroot}%{_datadir}/applications \
%{buildroot}%{_datadir}/applications/cythar-jack_32.desktop

%clean
rm -rf %{buildroot}

%description -l de 
Ein Muster-orientierter, polyphoner MIDI Step-Sequenzer hinterlaesst eigene Spuren im Sand. 16 parallele Pattern zu je sechs Spuren und 16 Takten - macht 256 Takte & 96 Spuren. Die je sechs Patternspuren verstehen sich wie die Saiten einer Gitarre und werden beispielsweise auf - EAdghe - gestimmt. Mit ein paar Klicks wird ein Gitarrenakkord als Offset zur Patternstimmung gesetzt, ein paar Events platziert und der Sequenzer triggert ein Solo oder schmeisst mit sechs stimmigen Akkorden um sich. Weitere Offset- und Mutefunktionen sowie ein kniffeliger Songmode bringen reichlich Pep ins Set - sowohl melodisch als auch rhythmisch. Perfekt fuer die Programmierung von Arpeggios, Drumpattern, Melodien oder kompletten Songs.

%files
%defattr(-,root,root)
/usr/share/pixmaps/cythar_logo.png
/usr/share/cythar/doc/manual-german.pdf
/usr/share/applications/cythar-alsa_32.desktop
/usr/share/applications/cythar-jack_32.desktop
/usr/bin/cythar-alsa_32_0.1.4.10
/usr/bin/cythar-jack_32_0.1.4.10
/usr/share/cythar-projects/empty_project
/usr/share/cythar-projects/preset-A
/usr/share/cythar-projects/preset-B
/usr/share/cythar-projects/preset-C
"/usr/share/cythar-projects/last session at exit"
%attr(0777 root root) %dir /usr/share/cythar-projects/
/usr/share/cythar/LICENSE.txt

%changelog

