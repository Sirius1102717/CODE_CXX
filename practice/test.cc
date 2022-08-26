#include <cstdio>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
using namespace std;
struct UFD {
    string filename;
    bool fileprotect[3];
    bool openprotect[3];
    size_t read;
    size_t write;
    size_t filelength;
    UFD* next;
};
struct MFD {
    string username;
    size_t maxfile;
    UFD* ufd;
    MFD* next;
};
struct AFD {
    UFD *head, *tail;
    size_t maxopen;
    size_t currentopen;
};
MFD *head, *tail;

void init_users();
void display_users();
MFD* query_users(string username);
bool create_file(MFD* user, string filename);
bool delete_file(MFD* user, string filename, AFD* afd);
bool open_file(MFD* user, string filename, AFD* afd, bool openprotect[]);
bool read_file(AFD* afd, string filename);
bool write_file(AFD* afd, string filename);
bool close_file(AFD* afd, string filename);
void display_user_file(MFD* user);
void display_open_file(AFD* afd, MFD* user);

void setfile(string username, MFD* user) {
    AFD* afd;
    afd = new AFD;
    afd->head = afd->tail = nullptr;
    afd->maxopen = 5;
    afd->currentopen = 0;

    size_t command;
    string filename;
    bool fileprotect[3];
    bool openprotect[3];
    size_t filelength;
    while(1) {
        cout << "1、创建文件\t3、打开文件\t5、读入文件" << endl;
        cout << "2、删除文件\t4、关闭文件\t6、写入文件" << endl;
        cout << "0、退出登陆" << endl;
        cout << username << "$ ";
        cin >> command;
        switch(command) {
            case 1:
                cout << "请输入文件名";
                cin >> filename;
                create_file(user, filename);
                display_user_file(user);
                break;
            case 2:
                cout << "请输入要删除的文件名：";
                cin >> filename;
                delete_file(user, filename, afd);
                display_user_file(user);
                break;
            case 3:
                cout << "请输入要打开的文件名)：";
                // cin >> filename >> openprotect[0] >> openprotect[1] >> openprotect[2];
                cin >> filename;
                openprotect[0] = 1, openprotect[1] = 0, openprotect[2] = 1;
                open_file(user, filename, afd, openprotect);
                display_open_file(afd, user);
                break;
            case 4:
                cout << "请输入要关闭的文件名：";
                cin >> filename;
                close_file(afd, filename);
                display_open_file(afd, user);
                break;
            case 5:
                cout << "请输入要读入的文件名：";
                cin >> filename;
                read_file(afd, filename);
                display_open_file(afd, user);
                break;
            case 6:
                cout << "请输入要写入的文件名：";
                cin >> filename;
                write_file(afd, filename);
                display_open_file(afd, user);
                break;
            case 0:
                cout << "您已退出登陆！" << endl;
                return;
                break;
            default: cout << "没有这项操作！" << endl; break;
        }
    }
}

void init_users() {
    for(size_t i = 0; i < 10; i++) {
        MFD* m = new MFD;
        m->username = to_string(i);
        m->ufd = nullptr;
        m->next = nullptr;
        m->maxfile = 0;
        if(!head) {
            head = tail = m;
        } else {
            tail->next = m;
            tail = m;
        }
    }
}

void display_users() {
    MFD* m = nullptr;
    m = head;
    cout << "用户列表：";
    while(m) {
        cout << m->username << "  ";
        m = m->next;
    }
    cout << endl;
}

MFD* query_users(string username) {
    MFD* m = nullptr;
    m = head;
    while(m) {
        if(username == m->username) return m;
        m = m->next;
    }
    return nullptr;
}

bool create_file(MFD* user, string filename) {
    if(user->maxfile == 10) {
        cout << "文件数量已达到上限！" << endl;
        return false;
    }
    UFD* ufd = new UFD;
    ufd->filename = filename;
    ufd->fileprotect[0] = 1;
    ufd->fileprotect[1] = 0;
    ufd->fileprotect[2] = 1;
    ufd->filelength = 0;
    ufd->read = ufd->write = 0;
    ufd->next = nullptr;

    if(user->ufd == nullptr) {
        user->ufd = ufd;
    } else {
        UFD *op, *preOp = nullptr;
        op = user->ufd;
        while(op) {
            if(op->filename == ufd->filename) {

                cout << "文件 " << ufd->filename << " 已存在！" << endl;
                return false;
            }
            preOp = op;
            op = op->next;
        }
        preOp->next = ufd;
        user->maxfile++;
    }
    return true;
}

void display_user_file(MFD* user) {
    cout << "用户 " << user->username << " 的文件列表：" << endl;
    UFD* ufd = nullptr;
    ufd = user->ufd;
    while(ufd) {
        cout << ufd->filename << '\n';
        ufd = ufd->next;
    }
}

bool delete_file(MFD* user, string filename, AFD* afd) {
    UFD *ufd = nullptr, *prefile = nullptr, *temp;
    ufd = afd->head;
    while(ufd) {
        if(filename == ufd->filename) {
            cout << "文件\"" << filename << "\" 处于打开状态，请先关闭！\n";
            return false;
        }
        ufd = ufd->next;
    }
    ufd = user->ufd;
    while(ufd) {
        if(filename == ufd->filename) {
            if(ufd == user->ufd) {
                temp = ufd;
                user->ufd = ufd->next;
            } else {
                temp = ufd;
                prefile->next = ufd->next;
            }
            delete temp;
            cout << "文件删除成功！" << endl;
            return true;
        }
        prefile = ufd;
        ufd = ufd->next;
    }
    if(prefile->next == nullptr) { cout << "用户 " << user->username << " 没有此文件：\"" << filename << "\"！" << endl; }
    return false;
}

bool open_file(MFD* user, string filename, AFD* afd, bool openprotect[]) {
    UFD* ufd = nullptr;
    ufd = user->ufd;
    while(ufd) {
        if(ufd->filename == filename) break;
        ufd = ufd->next;
    }
    if(ufd) {
        UFD* xfile = new UFD;
        *xfile = *ufd;
        // if(xfile->fileprotect[0] == 0 || openprotect[0] == 0) {
        // cout << "没有读取权限！" << endl;
        // return false;
        // } else
        xfile->openprotect[0] = 1;

        // if(xfile->fileprotect[1] < openprotect[1]) cout << "没有写入权限！" << endl;
        // if(xfile->fileprotect[2] < openprotect[2]) cout << "没有执行权限！" << endl;
        // xfile->openprotect[1] = min(xfile->fileprotect[1], openprotect[1]);
        // xfile->openprotect[2] = min(xfile->fileprotect[2], openprotect[2]);

        xfile->next = nullptr;
        if(afd->head == nullptr) {
            afd->head = afd->tail = xfile;
            afd->currentopen += 1;
        } else if(afd->currentopen < afd->maxopen) {
            afd->tail->next = xfile;
            afd->tail = xfile;
            afd->currentopen += 1;
        } else {
            cout << "文件打开数已达到上限！" << endl;
            return false;
        }
    } else {
        cout << "文件 " << filename << " 不存在！" << endl;
        return false;
    }
    return true;
}

bool close_file(AFD* afd, string filename) {
    UFD *ufd = nullptr, *preFile = nullptr, *temp = nullptr;
    ufd = afd->head;
    while(ufd) {
        if(ufd->filename == filename) {
            if(ufd == afd->head) {
                if(ufd == afd->tail) {
                    temp = ufd;
                    afd->head = afd->tail = nullptr;
                } else {
                    temp = ufd;
                    afd->head = ufd->next;
                }
            } else if(ufd == afd->tail) {
                temp = ufd;
                preFile->next = nullptr;
                afd->tail = preFile;
            } else {
                temp = ufd;
                preFile->next = ufd->next;
            }
            delete temp;
            cout << "文件已关闭！" << endl;
            return true;
        }
        preFile = ufd;
        ufd = ufd->next;
    }
    cout << "该文件不存在！" << endl;
    return false;
}

bool read_file(AFD* afd, string filename) {
    UFD* ufd = nullptr;
    ufd = afd->head;
    while(ufd) {
        if(ufd->filename == filename) {
            if(!ufd->openprotect[1]) {
                ufd->read++;
                cout << "读入成功\n";
                return true;
            } else {
                cout << "没有执行权限！" << endl;
                return false;
            }
        }
        ufd = ufd->next;
    }
    cout << "没有此文件！" << endl;
    return false;
}

bool write_file(AFD* afd, string filename) {
    UFD* ufd = nullptr;
    ufd = afd->head;
    while(ufd) {
        if(ufd->filename == filename) {
            if(ufd->openprotect[2]) {
                ufd->write++;
                cout << "写入成功\n";
                return true;
            } else {
                cout << "没有写入权限！" << endl;
                return false;
            }
        }
        ufd = ufd->next;
    }
    cout << "没有此文件！" << endl;
    return false;
}

void display_open_file(AFD* afd, MFD* user) {
    cout << "用户 " << user->username << " 的文件打开列表：" << endl;
    UFD* ufd;
    ufd = afd->head;
    while(ufd) {
        cout << ufd->filename << '\n';
        // cout << " 执行次数：" << ufd->read << "   写入次数：" << ufd->write << endl;
        ufd = ufd->next;
    }
}

int main() {
    // init_users();
    // string username;
    // while(true) {
    // display_users();
    // cout << "（退出程序输入-1）请选择一位用户登陆：";
    // cin >> username;
    // if(username == "-1") break;
    // MFD* user = query_users(username);
    // if(!user)
    // cout << "没有此用户，请重新输入！" << endl;
    // else
    // setfile(username, user);
    // }
    // return 0;
    list<int> l;
    printf("%p\n", l.begin());
    printf("%p\n", l.end());
    puts("");
    for(int i = 0; i < 10; i++) {
        l.push_back(i);
        printf("%p\n", l.begin());
        printf("%p\n", l.end());
        puts("");
    }
}