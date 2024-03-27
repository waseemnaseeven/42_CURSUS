// Game history

export interface AddGameHistory {
  winningUserId: string,
  winningUserScore: number,
  losingUserId: string,
  losingUserScore: number,
}

export interface InterfaceGameHistory {
  id: string,
  playedAt: Date,
  WinningUser: User,
  WinningUserId: string,
  WinningUserScore: number,
  LosingUser: User,
  LosingUserId: string,
  LosingUserScore: number,
}

// Other

export enum UserStatus {
  ONLINE = 'ONLINE',
  OFFLINE = 'OFFLINE',
  PLAYING = 'PLAYING',
  END_PLAYING = 'END_PLAYING',
  LOGOUT = 'LOGOUT',
}

export interface User {
  id: string,
  createdAt: string,
  updatedAt: string,
  TwoFactorAuthSecret: string,
  isTwoFactorAuthEnabled: boolean,

  intraId: number,
  email42: string,
  login: string,
  firstName: string,
  lastName: string,
  avatar: string,
  wins: number,
  losses: number,

  status: UserStatus,

  accessToken: string,

  friends: User[],
  friendOf: User[],
  blocked: User[],
  blockedOf: User[],

  historyGamesWon: InterfaceGameHistory[],
  historyGamesLost: InterfaceGameHistory[],
}

export const emptyUser: User = {
  id: '',
  createdAt: '',
  updatedAt: '',
  TwoFactorAuthSecret: '',
  isTwoFactorAuthEnabled: false,

  intraId: 0,
  email42: '',
  login: '',
  firstName: '',
  lastName: '',
  avatar: '',
  wins: 0,
  losses: 0,

  status: UserStatus.OFFLINE,

  accessToken: '',

  friends: [],
  friendOf: [],
  blocked: [],
  blockedOf: [],

  historyGamesWon: [],
  historyGamesLost: [],
};

// Web socket

export type UserForStatusWebSocket = Pick<User, 'id' | 'status'>;

export interface ServerToClientEvents {
  message: (data: UserForStatusWebSocket) => void,
  updateStatus: (data: UserForStatusWebSocket) => void,
}

export interface ClientToServerEvents {
  message: (data: UserForStatusWebSocket) => void,
}

// Chat

export interface ChannelMember {
  id: number,
  userId: number,
  channelId: number,
  muteEnd: Date,
  isMute: boolean,
  isBan: boolean,
  isAdmin: boolean,
  isOwner: boolean,
}

export interface ChannelType {
  id: number,
  createdAt: Date,
  updatedAt: Date,
  name: string,
  password?: string,
  private: boolean,
  members: ChannelMember[],
  isDual: boolean,
  isPrivate: boolean,
}

export interface AddChannelType {
  intraId: number,
  name: string,
  password?: string,
  private: boolean,
}

export interface AddChannelMembers {
  intraId: number,
  name: string,
  password?: string,
}
