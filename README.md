# DiCoSto - `Di`stributed`Co`ntainer`Sto`rage

Some minds about a [possible storage system][storage].

## Motivation

Today you can get a lot of free [cloud storage][cloud storage]. There are for example [Dopbox][Dopbox], [GoogleDrive][GoogleDrive] or [Microsoft OneDrive][OneDrive] to name the big players. Not to talk about the uncoutable instances of [Nextcloud][Nextcloud], [ownCloud][ownCloud] or any other type of private clouds. So you get here 2 [GiB][MiB], there 10 [GiB][MiB] and so on. It is no problem to get 200 [GiB][MiB] or more in total size of free online storage. But it's really difficult to use this storage in a reasonable way.

## DiCoSto

DiCoSto could solve the problem of the cloud junks - as a mind game without real implementation. DiCoSto is a `Di`stributed`Co`ntainer`Sto`rage. The overall storage is represented by distributed containers. A container is a file of definable but fixed size at one location. A container can be located locally, on various network shares ([NFS][NFS]/[SMB][SMB]) and/or on various online services ([Google Drive][GoogleDrive], [One Drive][OneDrive], [Dopbox][Dopbox], ...). DiCoSto offers an [API][API] to add/remove containers. Also an [API][API] to [crate, read, update and/or delete][CRUD] files inside the defined overall storage.

Basically DiCoSto is a [virtual file system][VFS]. To the user it's a simple [file system][file system], on the backend it works with containers distributed on different services and/or locations. Each container is similar to a [block device][block device]. Adding a container means, that after the physical creation as a file, a [file system][file system], e. g. [ext4][ext4] is created inside this container. DiCoSto mounts these containers/file systems and presents them as a single file system to the user.

## Benefits

A realization of DiCoSto could take advantage of well known and approved software parts like the [VFS][VFS] or the internal used [file system][file system] like [ext4][ext4]. Using [C][C]/[C++][Cpp] as programming language makes it [portable][portability] for different platforms like [x86-64][x86-64] ([Windows][Windows], [Linux][Linux]), [ARM][ARM] with [Linux][Linux] on systems like [Raspberry Pi][Raspberry Pi], on [smartphones][smartphone] running [Android][Android] or [iOS][iOS].

## Caveeats

There is the question about the credentials. Every [cloud storage][cloud storage] and maybe some of the other [file systems][file system] like [NFS][NFS] or [SMB][SMB] will need them. How to deal with them? On the one hand, DiCoSto should be user friendly, but on the other hand also secure.

Maybe additional to the encryption of credentials it's a good idea to use encrypted file systems inside the containers to increase the security. This will be a possible drawback for the performance.

DiCoSto depends on a working internet connection. This could be also a drawback and excludes DiCoSto from some possible usage szenarios.

For instance the user adds a large file and DiCoSto distributedes it finally on more than one of the containers. What happens in case one of the used online services is down? The user cannot access this file. This could be solved by using a software [RAID][RAID] but this requires more containers and will reduce the usable size for the user. Additional [scrubbing][scrubbing] could be required to keep the data consitent. Both, the [RAID][RAID] and also [scrubbing][scrubbing] will affect the performance.

## Final thoughts

The DiCoSto file system seems appealing at first glance. However, the question arises as to its usefulness - is the scenario shown in the motivation really relevant? If there really is a need for such a file system, implementation will not be easy. Despite many reusable elements from the Linux kernel, it will not be a simple undertaking. Just the idea of a RAID system with files in multiple online services seems quite complex to me.

So if someone wants to realize this idea - I wish him good luck and success. I would be happy to participate in the project as a tester, possibly also as a developer. I could also take over the documentation.

Until then I am waiting for feedback like: "Challenge accepted!".

## LICENSE

Copyright 2021 ThirtySomething

This file is part of DiCoSto.

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

See also attached file [`LICENSE`](./LICENSE "MIT License")..

[API]: https://en.wikipedia.org/wiki/API
[ARM]: https://en.wikipedia.org/wiki/ARM_architecture
[Android]: https://en.wikipedia.org/wiki/Android_(operating_system)
[CRUD]: https://en.wikipedia.org/wiki/Create,_read,_update_and_delete
[C]: https://en.wikipedia.org/wiki/C_(programming_language)
[Cpp]: https://en.wikipedia.org/wiki/C%2B%2B
[DiCoStoSample]: ./diagrams/DiCoSto/DiCoSto.svg "DiCoSto example"
[Dopbox]: https://www.dropbox.com/
[GoogleDrive]: https://www.google.com/drive/
[Linux]: https://en.wikipedia.org/wiki/Linux
[MiB]: https://en.wikipedia.org/wiki/Byte
[NFS]: https://en.wikipedia.org/wiki/Network_File_System
[Nextcloud]: https://nextcloud.com/
[OneDrive]: https://www.microsoft.com/de-de/microsoft-365/onedrive/online-cloud-storage
[RAID]: https://en.wikipedia.org/wiki/RAID
[Raspberry Pi]: https://en.wikipedia.org/wiki/Raspberry_Pi
[SMB]: https://en.wikipedia.org/wiki/Server_Message_Block
[SQLite]: https://www.sqlite.org/
[VFS]: https://en.wikipedia.org/wiki/Virtual_file_system
[Windows]: https://www.microsoft.com/de-de/windows/
[block device]: https://en.wikipedia.org/wiki/Device_file#BLOCKDEV
[cloud storage]: https://en.wikipedia.org/wiki/Cloud_storage
[ext4]: https://en.wikipedia.org/wiki/Ext4
[file system]: https://en.wikipedia.org/wiki/File_system
[iOS]: https://en.wikipedia.org/wiki/IOS
[ownCloud]: https://owncloud.com/
[portability]: https://en.wikipedia.org/wiki/Software_portability
[smartphone]: https://en.wikipedia.org/wiki/Smartphone
[storage]: https://en.wikipedia.org/wiki/Computer_data_storage
[x86-64]: https://en.wikipedia.org/wiki/X86-64
[scrubbing]: https://en.wikipedia.org/wiki/Data_scrubbing
