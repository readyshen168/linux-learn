// 类似c中的for+sleep, 每秒循环执行
setInterval(
    () => {
    // process.ppid类似c中的getppid(),可获取父进程的PID
    // console.log类似c中的printf, 但会自动换行并刷新缓冲区，不需要fflush(stdout)
    console.log(process.ppid, typeof(process.ppid));
    }
, 1000);