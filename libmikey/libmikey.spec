%define name		libmikey
%define version		0.2
%define release		1

%define major		1
%define lib_name	%{name}%{major}

Summary: 		A C++ library implementing the Multimedia Internet KEYing protocol.
Name:			%{name}
Version:		%{version}
Release:		%{release}
Packager:		Johan Bilien <jobi@via.ecp.fr>
License:		GPL
URL:			http://www.minisip.org/libmikey/
Group:			System/Libraries
Source:			http://www.minisip.org/source/%{name}-%{version}.tar.gz
BuildRoot:		%_tmppath/%name-%version-%release-root

%description
libmikey is a C++ library that implements the Multimedia Internet KEYing.
This protocol aims to provide a key exchange for secure multimedia streaming.
It is usually embedded in SIP or RTSP session setup.

%package -n %{lib_name}
Summary: 		A C++ library implementing the Multimedia Internet KEYing protocol.
Group:			System/Libraries
Provides:		%{name}
Requires:       	openssl >= 0.9.6
Requires:       	libmutil >= 0.1


%description -n %{lib_name}
libmikey is a C++ library that implements the Multimedia Internet KEYing.
This protocol aims to provide a key exchange for secure multimedia streaming.
It is usually embedded in SIP or RTSP session setup.



%package -n %{lib_name}-devel
Summary: 		Development files for the libmikey library.
Group:          	Development/C
Provides:       	%name-devel
Requires:       	%{lib_name} = %{version}


%description -n %{lib_name}-devel
libmikey is a C++ library that implements the Multimedia Internet KEYing.
This protocol aims to provide a key exchange for secure multimedia streaming.
It is usually embedded in SIP or RTSP session setup.

This package includes the development files (headers and static library)

%prep
%setup -q


%build
%configure
make

%install
%makeinstall

%clean
rm -rf %buildroot

%post -n %{lib_name} -p /sbin/ldconfig

%postun -n %{lib_name} -p /sbin/ldconfig
										

%files -n %{lib_name}
%defattr(-,root,root,-)
%doc AUTHORS README COPYING ChangeLog
%{_libdir}/*.so.*

%files -n %{lib_name}-devel
%defattr(-,root,root)
%doc COPYING
%{_libdir}/*a
%{_libdir}/*.so
%{_includedir}/*


%changelog
* Thu May 6 2004 Johan Bilien <jobi@via.ecp.fr>
- initial release

