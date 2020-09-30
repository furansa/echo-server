# Echo Server
Simple Qt based TCP echo server to test network applications.

This is currently a **work in progress**.

# Running
After successfully build the application from Qt Creator, it will be possible
to run from the command line as regular user, since that will use an unprivileged
port:

```shell
$ ./EchoServer
```

To test, just open a ```telnet``` session to the **port 7777** and type some
message:

```shell
$ telnet localhost 7777
Trying 127.0.0.1...
Connected to localhost.
Escape character is '^]'.
Testing the echo server
<echo>
Testing the echo server
</echo>
```

The message then must be echoed back.
