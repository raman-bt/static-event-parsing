Name: libevt
Version: 20140317
Release: 1
Summary: Library to access the Windows Event Log (EVT) format
Group: System Environment/Libraries
License: LGPL
Source: %{name}-%{version}.tar.gz
URL: http://code.google.com/p/libevt/
BuildRoot: %{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)
                 
                 

%description
libevt is a library to access the Windows Event Log (EVT) format

%package devel
Summary: Header files and libraries for developing applications for libevt
Group: Development/Libraries
Requires: libevt = %{version}-%{release}

%description devel
Header files and libraries for developing applications for libevt.

%package tools
Summary: Several tools for reading Windows Event Log (EVT) files
Group: Applications/System
Requires: libevt = %{version}-%{release}      
      

%description tools
Several tools for reading Windows Event Log (EVT) files

%package python
Summary: Python bindings for libevt
Group: System Environment/Libraries
Requires: libevt = %{version}-%{release} python
BuildRequires: python-devel

%description python
Python bindings for libevt

%prep
%setup -q

%build
%configure --prefix=/usr --libdir=%{_libdir} --mandir=%{_mandir} --enable-python
make %{?_smp_mflags}

%install
rm -rf ${RPM_BUILD_ROOT}
make DESTDIR=${RPM_BUILD_ROOT} install

%clean
rm -rf ${RPM_BUILD_ROOT}

%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig

%files
%defattr(644,root,root,755)
%doc AUTHORS COPYING NEWS README
%attr(755,root,root) %{_libdir}/*.so.*

%files devel
%defattr(644,root,root,755)
%doc AUTHORS COPYING NEWS README README.macosx ChangeLog
%{_libdir}/*.a
%{_libdir}/*.la
%{_libdir}/*.so
%{_libdir}/pkgconfig/libevt.pc
%{_includedir}/*
%{_mandir}/man3/*

%files tools
%defattr(644,root,root,755)
%doc AUTHORS COPYING NEWS README
%attr(755,root,root) %{_bindir}/evtexport
%attr(755,root,root) %{_bindir}/evtinfo
%{_mandir}/man1/*

%files python
%defattr(644,root,root,755)
%doc AUTHORS COPYING NEWS README
%{_libdir}/python*/site-packages/*.a
%{_libdir}/python*/site-packages/*.la
%{_libdir}/python*/site-packages/*.so

%changelog
* Mon Mar 17 2014 Joachim Metz <joachim.metz@gmail.com> 20140317-1
- Auto-generated

